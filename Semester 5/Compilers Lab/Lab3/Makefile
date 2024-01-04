ass3_20CS10067_20CS30008_output.txt: lex
	./lex < ass3_20CS10067_20CS30008_test.c > ass3_20CS10067_20CS30008_output.txt

lex: lex.yy.c
	cc lex.yy.c -lfl -o lex

lex.yy.c: ass3_20CS10067_20CS30008.l ass3_20CS10067_20CS30008.c
	flex ass3_20CS10067_20CS30008.l ass3_20CS10067_20CS30008.c

clean:
	rm lex lex.yy.c ass3_20CS10067_20CS30008_output.txt
