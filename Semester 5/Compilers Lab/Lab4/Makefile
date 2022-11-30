asgn4_20CS10067_20CS30008_output.txt: parser asgn4_20CS10067_20CS30008_test.c
	./parser < asgn4_20CS10067_20CS30008_test.c > asgn4_20CS10067_20CS30008_output.txt

parser: lex.yy.o y.tab.o asgn4_20CS10067_20CS30008.o
	gcc lex.yy.o y.tab.o asgn4_20CS10067_20CS30008.o -lfl -o parser

asgn4_20CS10067_20CS30008.o: asgn4_20CS10067_20CS30008.c
	gcc -c asgn4_20CS10067_20CS30008.c

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

y.tab.o: y.tab.c
	gcc -c y.tab.c

lex.yy.c: asgn4_20CS10067_20CS30008.l y.tab.h
	flex asgn4_20CS10067_20CS30008.l

y.tab.c y.tab.h: asgn4_20CS10067_20CS30008.y
	bison -dty --report=all asgn4_20CS10067_20CS30008.y

clean:
	rm parser asgn4_20CS10067_20CS30008.o lex.yy.* y.tab.* y.output
