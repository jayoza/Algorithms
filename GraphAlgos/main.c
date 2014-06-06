#include<stdio.h>
#include "Graph.h"
#include<time.h>

int main(int argc, char *argv[]){
  graphPtr graph;
  FILE *fp;
  int i, output;
  double time_spent;
  struct timespec start, end;

  /*  if(argc!=5){
    fprintf(stderr,"Please Enter: <a.out> <no.of nodes> <input file> <start vetex> <end vertex>\n");
    return -1;
    }*/
  
  int size=atoi(argv[1]);//, src=atoi(argv[3]), dest=atoi(argv[4]);

  /*if(src<=0 || dest<=0 || src>size || dest>size){
    fprintf(stderr,"[ERROR!!] : Invalid vertices! Please enter positive vertex entries less than or equal to %d\n", size);
    return -1;
    }
  */
  fp=fopen(argv[2], "r");
  
  clock_gettime(CLOCK_REALTIME, &start);
  printf("[FIRST STEP] : Initializing Graph ...\n");
  graph=createGraph(size);
 
  printf("[SECOND STEP] : Adding Edges ...\n");
  readGraph(fp, graph);
  clock_gettime(CLOCK_REALTIME, &end);
 
   time_spent=(double)((end.tv_sec*1000000000L + end.tv_nsec)-(start.tv_sec*1000000000L+start.tv_nsec))/(double)1000000000L;
  printf("Time to build Graph : %fs\n", time_spent);

  /*computing connectivity of two nodes
  if(bfs(graph, src-1, dest-1)>0){
    printf("YES nodes %d and %d are connected\n",src, dest);
  }
  else printf("NO nodes %d and %d are not connected\n", src, dest);
 */
  output=connectivity(graph);
  
  printf("No of Components in the Graph : %d\n", output); 
  /*for(i=0; i<size; i++)
    printf("%d ", output[i]);
  */

  /*clock_gettime(CLOCK_REALTIME, &start);
  connectivity(graph);
  clock_gettime(CLOCK_REALTIME, &end);
  
  time_spent=(double)((end.tv_sec*1000000000L + end.tv_nsec)-(start.tv_sec*1000000000L+start.tv_nsec))/(double)1000000000L;
  printf("Time to compute SCCs : %fs\n", time_spent);

  /*freeing the memory allocated to the graph*/
  destroyGraph(graph);

  fclose(fp);
  return 0;
}

