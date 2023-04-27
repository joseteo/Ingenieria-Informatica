COMP=g++

cadenas: lex.yy.cc
	$(COMP) $^ -o $@

lex.yy.cc: cadenas.l
	flex++ $^

ejemplo:
	./cadenas texto.txt

mr.proper:
	rm -f cadenas lex.yy.cc
