test: parser.out
	@echo "Running test 1 (Arithmatic, Shift and Bit operations)"
	./parser.out < ass5_20CS10067_20CS30008_test1.c > ass5_20CS10067_20CS30008_quads1.out
	@echo "Test 1 complete\n"

	@echo "Running test 2 (Relational, Boolean, Unary Operator)"
	./parser.out < ass5_20CS10067_20CS30008_test2.c > ass5_20CS10067_20CS30008_quads2.out
	@echo "Test 2 complete\n"

	@echo "Running test 3 (Loops and If-Else Block)"
	./parser.out < ass5_20CS10067_20CS30008_test3.c > ass5_20CS10067_20CS30008_quads3.out
	@echo "Test 3 complete\n"

	@echo "Running test 4 (Arrays and pointers)"
	./parser.out < ass5_20CS10067_20CS30008_test4.c > ass5_20CS10067_20CS30008_quads4.out
	@echo "Test 4 complete\n"

	@echo "Running test 5 (Declarations, Assignments and Function calls)"
	./parser.out < ass5_20CS10067_20CS30008_test5.c > ass5_20CS10067_20CS30008_quads5.out
	@echo "Test 5 complete\n"

	@echo "Running test 6 (Overall Test File)"
	./parser.out < ass5_20CS10067_20CS30008_test6.c > ass5_20CS10067_20CS30008_quads6.out
	@echo "Test 6 complete\n"

parser.out: lex.yy.o y.tab.o ass5_20CS10067_20CS30008_translator.o
	g++ lex.yy.o y.tab.o ass5_20CS10067_20CS30008_translator.o -lfl -o parser.out

ass5_20CS10067_20CS30008_translator.o: ass5_20CS10067_20CS30008_translator.cxx ass5_20CS10067_20CS30008_translator.h
	g++ -c ass5_20CS10067_20CS30008_translator.cxx

lex.yy.o: lex.yy.c
	g++ -c lex.yy.c

y.tab.o: y.tab.c
	g++ -c y.tab.c

lex.yy.c: ass5_20CS10067_20CS30008.l y.tab.h ass5_20CS10067_20CS30008_translator.h
	flex ass5_20CS10067_20CS30008.l

y.tab.c y.tab.h: ass5_20CS10067_20CS30008.y
	bison -dty --report=all ass5_20CS10067_20CS30008.y

clean:
	rm ass5_20CS10067_20CS30008_translator.o lex.yy.* *.out y.tab.* y.output