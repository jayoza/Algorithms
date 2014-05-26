CC=gcc
LINKS1=-lrt
LINKS2=-pthread $(LINKS1)
OPT=-O2

#make para for parallel mergesort compilation
para : test.o readi.o pmergesort.o
	$(CC) -o parallelmsort test.o readi.o pmergesort.o $(LINKS2)

#make seq for sequential mergesort compilation
seq : test.o readi.o mergesort.o
	$(CC) -o seqmsort test.o readi.o mergesort.o $(LINKS1)

test.o : test.c
	$(CC) -c test.c $(OPT)

readi.o : readi.c
	$(CC) -c readi.c $(OPT)

pmergesort.o : pmergesort.c
	$(CC) -c pmergesort.c $(OPT)

mergesort.o : mergesort.c
	$(CC) -c mergesort.c $(OPT)	

clean : 
	rm -rf *.o parallelmsort seqmsort

rebuild : clean para