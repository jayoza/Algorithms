#include<stdio.h>
#include<stdlib.h>
#include "Graph.h"

inline void err_exit(char *msg){
  printf("[Fatal Error]:%s \nExiting....\n",msg);
  exit(1);
}

nodePtr createNode(int v){
  nodePtr newNode=(nodePtr)malloc(sizeof(Node));
  if(!newNode)
    err_exit("Unable to allocate memory for node");
  
  newNode->vertex=v;
  newNode->next=NULL;
  
  return newNode;
}

graphPtr createGraph(int n){
  int i;
  graphPtr graph=(graphPtr)malloc(sizeof(Graph));
  if(!graph)
    err_exit("Unable to allocate memory for Graph");
  
  graph->num_vertices=n;
  graph->listarr=(listPtr)malloc(n*sizeof(List));
  if(!graph->listarr)
    err_exit("Unable to allocate memory for adjacency list"); 

  for(i=0; i<n; i++){
    graph->listarr[i].head=NULL;
    graph->listarr[i].length=0;
  }

  return graph;
}

void addEdge(graphPtr graph, int src, int dest){
  nodePtr newnode=createNode(dest);
  newnode->next=graph->listarr[src].head;
  graph->listarr[src].head=newnode;
  graph->listarr[src].length++;
}

void destroyGraph(graphPtr g){
  if(g){
    if(g->listarr){
      int v;
      for(v=0; v<g->num_vertices; v++){
	nodePtr adjlistptr=g->listarr[v].head;
	while(adjlistptr){
	  nodePtr tmp=adjlistptr;
	  adjlistptr=adjlistptr->next;
	  free(tmp);
	}
      }
      free(g->listarr);
    }
    free(g);
  }
}
      
void displayGraph(graphPtr g){
  int i;

  for(i=0; i<g->num_vertices; i++){
    nodePtr adj=g->listarr[i].head;
    printf("\n%d: ", i);
    while(adj){
      printf("%d->", adj->vertex);
      adj=adj->next;
    }
    printf("NULL\n");
  }
}   
