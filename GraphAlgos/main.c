#include<stdio.h>
#include "Graph.h"

int main(int argc, char *argv[]){
  graphPtr graph;
  FILE *fp;
  int output;

  if(argc!=5){
    fprintf(stderr,"Please Enter: <a.out> <no.of nodes> <input file> <start vetex> <end vertex>\n");
    return -1;
  }
  
  int size=atoi(argv[1]), src=atoi(argv[3]), dest=atoi(argv[4]);

  if(src<=0 || dest<=0 || src>size || dest>size){
    fprintf(stderr,"[ERROR!!] : Invalid vertices! Please enter positive vertex entries less than %d\n", size);
    return -1;
  }
   
  fp=fopen(argv[2], "r");

  printf("[FIRST STEP] : Initializing Graph ...\n");
  graph=createGraph(size);
 
  printf("[SECOND STEP] : Adding Edges ...\n");
  read(fp, graph);
 
  /* computing connectivity of two nodes*/
  if((output=bfs(graph, src-1, dest-1))>0){
    printf("YES nodes %d and %d are connected\n",src, dest);
  }
  else if(output==0) printf("NO nodes %d and %d are not connected\n", src, dest);
  
  /*freeing the memory allocated to the graph*/
  destroyGraph(graph);

  fclose(fp);
  return 0;
}

