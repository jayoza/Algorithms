#include<stdio.h>

typedef struct param Param;

void sort(int *, int, int);
int partition(int *, int, int);
void swap(int *, int, int);

void quicksort(int *a, int sz){
  sort(a, 0, sz-1);
}

void sort(int *a, int lo, int hi){
  int p;
 
  /* Base case */
  if(hi<=lo) return;

  /* Partition about the pivot */
  p=partition(a, lo, hi);
  /*counting comparisons for left subarray*/
  sort(a, lo, p-1);
  /*counting comparisons for right subarray*/
  sort(a, p+1, hi);
}

int partition(int *a, int lo, int hi){
  int pivot, temp, median;
  int i=lo+1, j;
  int mid=(hi+lo)/2;
  
  /*choosing the first element of the array as the pivot*/
  pivot=a[lo];

  for(j=lo+1; j<=hi; j++){
    if(a[j]<=pivot){
      swap(a,i,j);
      i++;
    }
  }
 
  /*swapping the first element with the pivot position calculated above*/
  swap(a,i-1,lo);

  return i-1;
}
  
void swap(int *a, int i, int j){
  int temp;
  
  temp=a[i];
  a[i]=a[j];
  a[j]=temp;
}
