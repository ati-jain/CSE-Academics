out:	goodmalloc.o mergesort.o
	g++ -o mergesort goodmalloc.o mergesort.o

goodmalloc.o:	goodmalloc.h goodmalloc.cpp
	g++ -c goodmalloc.cpp

mergesort.o:	goodmalloc.h mergesort.c
	g++ -c mergesort.c

run:	mergesort
	./mergesort

clean:
	rm -f *.o mergesort