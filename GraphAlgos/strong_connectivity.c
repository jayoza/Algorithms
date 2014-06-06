#include<stdio.h>
#include<stdlib.h>
#include "Graph.h"

int *hifive, *order, *explored, n;
int count;

void dfs_routine1(graphPtr graph, int src);
void dfs_routine2(graphPtr graph, int src);

void connectivity(graphPtr graph){
  graphPtr graphrev;
  nodePtr adjacent;
  int i, current, comp=0, min=0, j;
  
  count=0; 
  n=graph->num_vertices;
 
  order=(int *)malloc(n*sizeof(int));
  hifive=(int *)malloc(5*sizeof(int));
  explored=(int *)malloc(n*sizeof(int));

  graphrev=createGraph(n);

  for(i=0; i<n; i++)
    explored[i]=0;

  for(i=0; i<5; i++)
    hifive[i]=0;

  for(i=0; i<n; i++){
    adjacent=graph->listarr[i].head;
   
    while(adjacent){
      current=adjacent->vertex;
      addEdge(graphrev, current, i);
      adjacent=adjacent->next;
    }
  }
 
  for(i=n-1; i>=0; i--){
    if(!explored[i]){
      dfs_routine1(graphrev, i);
    }
  }
  
  for(i=0; i<n; i++){
    explored[i]=0;
  }
  
  for(i=n-1; i>=0; i--){
    if(!explored[order[i]]){
      count=0;
      dfs_routine2(graph, order[i]);
      if((count+1)>hifive[min]){
	hifive[min]=count+1;
      }
      for(j=0; j<5; j++){
      	if(hifive[j]<hifive[min])min=j;
      }
    }
  }
  
  printf("\n---The size of 5 largest components--- \n");
  for(i=0; i<5; i++)
    printf("%d\n",hifive[i]);
    
  free(explored);
  free(order);
  destroyGraph(graphrev);
}
  
void dfs_routine1(graphPtr graph, int src){
  nodePtr adjacent=graph->listarr[src].head;
  int current;
  
  explored[src]=1;
 
  while(adjacent){
    current=adjacent->vertex;
    if(!explored[current]){
      explored[current]=1;
      dfs_routine1(graph, current);
    }    
    adjacent=adjacent->next;
  }
  order[count++]=src;
}

void dfs_routine2(graphPtr graph, int src){
  nodePtr adjacent=graph->listarr[src].head;
  int current;
 
  explored[src]=1;
  
  while(adjacent){
    current=adjacent->vertex;
    if(!explored[current]){
      count++;
      explored[current]=1;
      dfs_routine2(graph, current);
    }
    adjacent=adjacent->next;
  }
}
