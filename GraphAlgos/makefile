CC=gcc
OPT=-O2

bfs : main.o Graph.o readfile.o queue.o bfs.o
	$(CC) -o bfs Graph.o main.o readfile.o queue.o bfs.o

connectivity : main.o Graph.o readfile.o queue.o connectivity.o
	$(CC) -o connectivity Graph.o main.o readfile.o queue.o connectivity.o

main.o : main.c
	$(CC) -c main.c $(OPT) 

readfile.o : readfile.c
	$(CC) -c readfile.c $(OPT) 

Graph.o : Graph.c
	$(CC) -c Graph.c $(OPT) 

bfs.o : bfs.c
	$(CC) -c bfs.c $(OPT) 

connectivity.o : connectivity.c
	$(CC) -c connectivity.c $(OPT)

queue.o : queue.c
	$(CC) -c queue.c $(OPT) 

clean : 
	rm -f *.o bfs connectivity

rebuild : clean bfs