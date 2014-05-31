#include<stdio.h>
#include "Graph.h"

int bfs(graphPtr graph, int start, int vertex){
  int n=graph->num_vertices;
  int explored[n], i, current;
  nodePtr adjacent;
 
  for(i=0; i<n; i++)
    explored[i]=0;

  /*set starting node as explored*/
  explored[start]=1;

  /*enqueue sarting node to the queue*/
  enqueue(start);
  
  while(!isEmpty()){
    current=dequeue();
    adjacent=graph->listarr[current].head;
    while(adjacent){
      if(!explored[adjacent->vertex]){
	explored[adjacent->vertex]=1;
	enqueue(adjacent->vertex);
      }
      adjacent=adjacent->next;
    }
  }

  if(explored[vertex]) return 1;
  else return 0;
}
  
  
  
  
  
  
