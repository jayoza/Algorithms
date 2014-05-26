#include<stdio.h>
#include<stdlib.h>
#include "Graph.h"

int main(int argc, char *argv[]){
  graphPtr graph;
  FILE *fp;
  int n_vertices=atoi(argv[1]);

  fp=fopen(argv[2], "r");
  
  graph=createGraph(n_vertices);
  fastread(fp, graph);

  
