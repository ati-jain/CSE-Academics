a.out: main.o libass2_20CS30008.a
	gcc main.o -L. -lass2_20CS30008
main.o: main.c myl.h
	gcc -Wall -c main.c
libass2_20CS30008.a: ass2_20CS30008.o
	ar -rcs libass2_20CS30008.a ass2_20CS30008.o
ass2_20CS30008.o: ass2_20CS30008.c myl.h
	gcc -c ass2_20CS30008.c
clean:
	rm a.out main.o libass2_20CS30008.a ass2_20CS30008.o