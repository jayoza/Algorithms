#include<stdio.h>
#include "Graph.h"

int connectivity(graphPtr graph){
  int n=graph->num_vertices;
  int explored[n], i, count=0;
  int current;
  nodePtr adjacent;

  for(i=0; i<n; i++)
    explored[i]=0;

  for(i=0; i<n; i++){
    if(!explored[i]){
      count++;
      explored[i]=1;
    }
    else continue;

    enqueue(i);

    while(!isEmpty()){
      current=dequeue();
      adjacent=graph->listarr[current].head;
      while(adjacent){
	if(!explored[adjacent->vertex]){
	  enqueue(adjacent->vertex);
	  explored[adjacent->vertex]=1;
	}
	adjacent=adjacent->next;
      }
    }
  }
  
  return count;
}
  
  
