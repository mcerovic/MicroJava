# bash je potreban da bi radila redirekcija stderr i stdout, kao i zbog PIPESTATUS promenljive
SHELL = /bin/bash
# fajlovi od kojih se sastoji kompajler
COMPILER_BUILD = lex.yy.c y.tab.c symtab.c semantic.c
# fajlovi od kojih zavisi ponovno prevođenje
COMPILER_DEPENDS = $(COMPILER_BUILD) defs.h symtab.h semantic.h
# fajlvi koje treba pobrisati da bi ostao samo izvorni kod
COMPILER_CLEAN = lex.yy.c y.tab.c y.tab.h y.output a.out *.?~ make.out?

LEX_SRC = scanner.l
YACC_SRC = parser.y

# pravila koja ne generišu nove fajlove
.PHONY: clean test all make.out

# potrebno da bi se pre ponovnog prevođenja obrisao .make.out1 fajl
all: .make.out1 a.out

# osnovno pravilo za prevođenje kompajlera
# .make.out1 služi za privremeno smeštanje svih ispisa prilikom prevođenja
# .make.out2 sadrži ispis poslednjeg uspešnog prevođenja
a.out: $(COMPILER_DEPENDS)
	@echo -e "\e[01;32mGCC...\e[00m"
	@-rm -f a.out .make.out2 2>/dev/null
	@gcc -m32 -o $@ $(COMPILER_BUILD) 2>&1 | tee -a .make.out1; pstat=$${PIPESTATUS[0]}; \
	if [ $$pstat -ne 0 ]; then rm -f .make.out1; fi; \
	exit $$pstat;
	@# provera da li ima više od jednog S/R konflikta
	@out=`grep conflicts < .make.out1`; if [[ "$$out" != "" && "$$out" != "conflicts: 1 shift/reduce" ]]; then \
	echo -e "\e[01;31m\n------ More than 1 S/R conflict! ------\n\e[00m" ; \
	fi
	@mv .make.out1 .make.out2

lex.yy.c: $(LEX_SRC) y.tab.c
	@echo -e "\e[01;32mLEX...\e[00m"
	@lex -I $< 2>&1 | tee -a .make.out1; exit $${PIPESTATUS[0]}

y.tab.c: $(YACC_SRC)
	@echo -e "\e[01;32mYACC...\e[00m"
	@yacc -d -v $< 2>&1 | tee -a .make.out1; exit $${PIPESTATUS[0]}

clean:
	@echo -e "\e[01;32mCLEAN...\e[00m"
	@rm -f $(COMPILER_CLEAN)

.make.out1:
	@-rm -f .make.out1
	@touch .make.out1

# testiranje kompajlera, izvršava se samo ako nema grešaka u gramatici
# - u petlji će se kompajleru proslediti svi test*.c fajlovi
# - ako u test fajlu postoji linija sa tekstom "//OPIS:", ispisaće se na ekranu
test: a.out
	@out=`grep conflicts < .make.out2`; \
	if [[ "$$out" != "" && "$$out" != "conflicts: 1 shift/reduce" ]]; then \
		echo -e "\e[01;31m\n------ More than 1 S/R conflict! ------\n\e[00m" ; \
		exit 1; \
	fi; \
	out=`grep warning < .make.out2`; \
	if [[ "$$out" != "" ]]; then \
		echo -e "\e[01;31m\n------ Warnings in grammar ------\n\e[00m" ; \
		exit 1; \
	fi; \
	for testgr in test-sanity test-ok test-syntax test-semantic; do\
		for test in $$testgr*.c; do \
			echo -e "\e[01;32m\n\n------------------------\nTesting: $$test"; \
			grep "//OPIS:" $$test; \
			echo -e "------------------------\e[00m"; \
			./a.out < $$test; \
			if [ $$? -ne 0 ]; then \
				echo -e "\e[01;31m\n------ Errors during compilation of '$$test'! ------\n\e[00m" ; \
			fi; \
		done; \
	done; \
	echo
