#include<stdio.h>

void sort(int *, int, int);
void merge(int *, int, int, int);

void merge_sort(int *a, int sz){
  int lo=0, hi=sz-1;
  sort(a, lo, hi);
}

void sort(int *a, int lo, int hi){
  int mid=(hi+lo)/2;

  if(lo>=hi) return;

  sort(a, lo, mid);
  sort(a, mid+1, hi);
  merge(a, lo, mid, hi);
}
  
void merge(int *a, int lo, int mid, int hi){
  int i=0, j=(mid-lo)+1, k, l, size=(hi-lo)+1;
  int aux[size];
    
  for(l=lo,k=0; l<=hi; l++){
    aux[k]=a[l];
    k++;
  }

  k=lo;

  while(k<=hi){
    if(j>(hi-lo)) a[k++]=aux[i++];
    else if(i>(mid-lo)) a[k++]=aux[j++];
    else if(aux[i]<=aux[j]) a[k++]=aux[i++];
    else {
      a[k++]=aux[j++];
    }
  }			 
}

