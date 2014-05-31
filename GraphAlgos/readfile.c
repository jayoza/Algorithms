#include<stdio.h>
#include "Graph.h"

void read(FILE *fp, graphPtr graph){
  char c=getc(fp);
  int src, dest, i;

  for(i=0; i<graph->num_vertices; i++){
    src=0;
    while(c<48 || c>57) c=getc(fp);

    while(c>=48 && c<=57){
      src=(src<<3)+(src<<1)+c-48;
      c=getc(fp);
    }
    
    while(c!='\n'){
      dest=0;
      
      while(c<48 || c>57){
	c=getc(fp);
	if(c=='\n') break;
      }
      
      if(c=='\n') break;

      while(c>=48 && c<=57){
	dest=(dest<<3)+(dest<<1)+c-48;
	c=getc(fp);
      }
 
      addEdge(graph, src-1, dest-1); 
    }
  }
}  
    
