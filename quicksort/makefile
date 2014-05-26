CC= gcc
FLAGS= -lrt
PFLAGS= -pthread $(FLAGS)
OPT= -O2

para : parallelsort.o test.o read.o
	$(CC) -o parallelqsort parallelsort.o test.o read.o $(PFLAGS)

seq : quicksort.o test.o read.o
	$(CC) -o seqqsort quicksort.o test.o read.o $(FLAGS)

parallelsort.o : parallelsort.c
	$(CC) -c parallelsort.c $(OPT)

test.o : test.c 
	$(CC) -c test.c $(OPT)

read.o : read.c
	$(CC) -c read.c $(OPT)

quicksort.o : quicksort.c
	$(CC) -c quicksort.c $(OPT)

clean : 
	rm -f *.o paralleqsort seqqsort

rebuild : clean para