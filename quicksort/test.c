#include<stdio.h>
#include<time.h>
#include "modules.h"

int main(int argc, char *argv[]){
  int sz=atoi(argv[1]);
  FILE *fp, *fo;
  int a[sz], i;
  struct timespec start, end;
  double time_spent;

  fp=fopen(argv[2], "r");

  /*reading the file data to the array a*/
  fastread(fp, a, sz);
  
  /*sorting the array using quicksort and returning the number if comparisons*/
  clock_gettime(CLOCK_REALTIME, &start);
  quicksort(a, sz);
  clock_gettime(CLOCK_REALTIME, &end);

  time_spent=(double)((end.tv_sec*1000000000L + end.tv_nsec)-(start.tv_sec*1000000000L+start.tv_nsec))/(double)1000000000L;

  printf("The time spent : %fms\n",time_spent*1000);

  fo=fopen(argv[3], "w");
  
  /*writing the sorted array contents to the output file*/
  for(i=0; i<sz; i++){
    fprintf(fo,"%d\n",a[i]);
  }

  fclose(fp);
  fclose(fo);

  return 0;
}
