assembly: parser.out libass2_20CS10067_20CS30008.a
	@echo "\n------------------- Generating Quads for the test files ---------------\n"

	./parser.out 1 > ass6_20CS10067_20CS30008_quads1.out
	./parser.out 2 > ass6_20CS10067_20CS30008_quads2.out
	./parser.out 3 > ass6_20CS10067_20CS30008_quads3.out
	./parser.out 4 > ass6_20CS10067_20CS30008_quads4.out
	./parser.out 5 > ass6_20CS10067_20CS30008_quads5.out
	./parser.out 6 > ass6_20CS10067_20CS30008_quads6.out
	./parser.out 7 > ass6_20CS10067_20CS30008_quads7.out

	@echo "\n-------------    Generating the object files from assembly code   ---------------\n"

	gcc -c ass6_20CS10067_20CS30008_1.s
	gcc -c ass6_20CS10067_20CS30008_2.s
	gcc -c ass6_20CS10067_20CS30008_3.s
	gcc -c ass6_20CS10067_20CS30008_4.s
	gcc -c ass6_20CS10067_20CS30008_5.s
	gcc -c ass6_20CS10067_20CS30008_6.s
	gcc -c ass6_20CS10067_20CS30008_7.s

	@echo "\n-------------    Compiling the test files   ---------------\n"

	gcc ass6_20CS10067_20CS30008_1.o -o test1 -L. -lass2_20CS10067_20CS30008 -no-pie
	gcc ass6_20CS10067_20CS30008_2.o -o test2 -L. -lass2_20CS10067_20CS30008 -no-pie
	gcc ass6_20CS10067_20CS30008_3.o -o test3 -L. -lass2_20CS10067_20CS30008 -no-pie
	gcc ass6_20CS10067_20CS30008_4.o -o test4 -L. -lass2_20CS10067_20CS30008 -no-pie
	gcc ass6_20CS10067_20CS30008_5.o -o test5 -L. -lass2_20CS10067_20CS30008 -no-pie
	gcc ass6_20CS10067_20CS30008_6.o -o test6 -L. -lass2_20CS10067_20CS30008 -no-pie
	gcc ass6_20CS10067_20CS30008_7.o -o test7 -L. -lass2_20CS10067_20CS30008 -no-pie

	@echo "\n###########  Use ./test<i> for testing the ith file  ##########\n"

libass2_20CS10067_20CS30008.a:
	gcc -c ass2_20CS10067_20CS30008.c
	ar -rcs libass2_20CS10067_20CS30008.a ass2_20CS10067_20CS30008.o

parser.out: lex.yy.o ass6_20CS10067_20CS30008.tab.o ass6_20CS10067_20CS30008_translator.o ass6_20CS10067_20CS30008_target_translator.o
	g++ lex.yy.o ass6_20CS10067_20CS30008.tab.o ass6_20CS10067_20CS30008_translator.o ass6_20CS10067_20CS30008_target_translator.o -lfl -o parser.out

ass6_20CS10067_20CS30008_target_translator.o: ass6_20CS10067_20CS30008_target_translator.cxx
	g++ -c ass6_20CS10067_20CS30008_target_translator.cxx

ass6_20CS10067_20CS30008_translator.o: ass6_20CS10067_20CS30008_translator.cxx ass6_20CS10067_20CS30008_translator.h
	g++ -c ass6_20CS10067_20CS30008_translator.h
	g++ -c ass6_20CS10067_20CS30008_translator.cxx

lex.yy.o: lex.yy.c
	g++ -c lex.yy.c

ass6_20CS10067_20CS30008.tab.o: ass6_20CS10067_20CS30008.tab.c
	g++ -c ass6_20CS10067_20CS30008.tab.c

lex.yy.c: ass6_20CS10067_20CS30008.l ass6_20CS10067_20CS30008.tab.h ass6_20CS10067_20CS30008_translator.h
	flex ass6_20CS10067_20CS30008.l

ass6_20CS10067_20CS30008.tab.h ass6_20CS10067_20CS30008.tab.c: ass6_20CS10067_20CS30008.y
	bison -dtv ass6_20CS10067_20CS30008.y -W


	
clean:
	rm  lex.yy.c\
		ass6_20CS10067_20CS30008.tab.c\
		ass6_20CS10067_20CS30008.tab.h\
		*.o\
		ass6_20CS10067_20CS30008.output\
		test1\
		test2\
		test3\
		test4\
		test5\
		test6\
		test7\
		*.out\
		ass6_20CS10067_20CS30008_translator.h.gch\
		libass2_20CS10067_20CS30008.a\
		*.s\
