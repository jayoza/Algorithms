#include<stdio.h>
#include<time.h>
#include<sys/time.h>

int main(int argc, char *argv[]){
  int sz, i=0;
  char c;
  FILE *fp, *fo;
  double time_spent;
  struct timespec start, end;
  
  if(argc!=4){
    fprintf(stderr,"ERROR! Please enter total data size, input file, and output file\n\n");
    return -1;
  }   

  sz=atoi(argv[1]);
  int a[sz];
  
  fp=fopen(argv[2], "r");
  fo=fopen(argv[3], "w");
  
  /* Reading data from input file */
  fastread(fp, a, sz);

  /* Counting the number of inversions */
  clock_gettime(CLOCK_REALTIME, &start);
  merge_sort(a,sz);
  clock_gettime(CLOCK_REALTIME, &end);
  
  /* Calculating time spent to calculate number of inversions */
  time_spent=(double)((end.tv_sec*1000000000L + end.tv_nsec)-(start.tv_sec*1000000000L+start.tv_nsec))/(double)1000000000L;
  printf("Running time of the parallel mergesort algorithm : %fms\n", time_spent*1000);

  for(i=0; i<sz; i++){
    fprintf(fo, "%d\n", a[i]);
  }
  
  fclose(fp);
  fclose(fo);
    
  return 0;
}

  
