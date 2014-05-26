#include<stdio.h>
#include<stdlib.h>
#include "Graph.h"

nodePtr createNode(int v){
  nodePtr newNode=(nodePtr)malloc(Node);
  if(!newNode)
    err_exit("Unable to allocate memory for node");
  
  newNode->vertex=v;
  newNode->next=NULL;
  
  return newNode;
}

graphPtr createGraph(int n){
  int i;
  graphPtr graph=(graphPtr)malloc(Graph);
  if(!graph)
    err_exit("Unable to allocate memory for Graph");
  
  graph->list_Vertices=n;
  graph->listarr=(listPtr)malloc(List);
  if(!graph->listarr)
    err_exit("Unable to locate memory for adjacency list"); 

  for(i=0; i<n; i++){
    graph->listarr[i].head=NULL;
    graph->listarr[i].length=0;
  }

  return graph;
}

void addEdge(graphPtr graph, int src, int dest){
  nodePtr newnode=create(dest);
  graph->listarr[src-1].head->next=newnode;
  graph->listarr[src-1].head=newnode;
  graph->listarr[src-1]++;
}
