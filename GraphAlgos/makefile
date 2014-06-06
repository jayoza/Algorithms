CC=gcc
OPT=-O3
FLAGS=-lrt

bfs : main.o Graph.o readfile.o queue.o bfs.o
	$(CC) -o bfs Graph.o main.o readfile.o queue.o bfs.o $(FLAGS)

connectivity : main.o Graph.o readfile.o queue.o connectivity.o
	$(CC) -o connectivity Graph.o main.o readfile.o queue.o connectivity.o $(FLAGS)

strong_connectivity : main.o Graph.o readfile2.o strong_connectivity.o
	$(CC) -o strong_connectivity Graph.o main.o readfile2.o strong_connectivity.o $(FLAGS)

main.o : main.c
	$(CC) -c main.c $(OPT) 

readfile.o : readfile.c
	$(CC) -c readfile.c $(OPT)

redfile2.o : readfile2.c
	$(CC) -c readfile2.c $(OPT)

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