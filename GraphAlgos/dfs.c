#include<stdio.h>
#include<stdlib.h>
#include "Graph.h"

int n, * explored;
void dfs_routine(graphPtr , int );

int dfs(graphPtr graph, int src, int dest){
  int i; 

  n=graph->num_vertices;
  explored=(int *)malloc(n*sizeof(int));
  
  for(i=0; i<n; i++)
    explored[i]=0;

  dfs_routine(graph, src);
  
  if(explored[dest]){
    free(explored);
    return 1;
  }else {
    free(explored);
    return 0;
  }
}

void dfs_routine(graphPtr graph, int src){
  int current;
  nodePtr adjacent=graph->listarr[src].head;
  
  explored[src]=1;
  
  while(adjacent){
    current=adjacent->vertex;
    
    if(!explored[current]){
      explored[current]=1;
      dfs_routine(graph, current);
    }
 
    adjacent=adjacent->next;
  }
}
