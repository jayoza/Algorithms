#include<stdio.h>
#include<stdlib.h>
#include "Graph.h"

int *explored, count, n, *order;
void ordering(graphPtr , int );

int *dfs_loop(graphPtr graph){
  int i;
  
  n=graph->num_vertices;
  explored=(int *)malloc(n*sizeof(int));
  order=(int *)malloc(n*sizeof(int));
  count=n; 
  for(i=0; i<n; i++){
    if(!explored[i]){
      ordering(graph, i);
    }
  }
  
  return order;
}

void ordering(graphPtr graph, int src){
  int current;
  nodePtr adjacent=graph->listarr[src].head;
    
  explored[src]=1;
  while(adjacent){
    current=adjacent->vertex;
    
    if(!explored[current]){
      explored[current]=1;
      ordering(graph, current);
    }
    adjacent=adjacent->next;
  }
  order[src]=count--;
}

