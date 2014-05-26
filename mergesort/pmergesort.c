#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

/*Parallel mergesort- Each of the subarrays are solved using seperate threads till the subarray size becomes 1/4th the actual size of the array*/

struct param{
  int *a;
  int lo;
  int hi;
};

typedef struct param Param;

void *psort(void *);
void pmerge(int *, int, int, int);
void sort_help(int *, int, int);

int size;

void merge_sort(int *a, int sz){
  int lo=0, hi=sz-1, mid=(sz-1)/2, ret;
  pthread_t tid;
  pthread_attr_t attr;
  Param *p;
  
  size=sz;
  p=(Param *)malloc(sizeof(Param));
   
  p->a=a;
  p->lo=lo;
  p->hi=hi;

  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
  ret=pthread_create(&tid, &attr, psort, (void *)p);
  if(ret){
    printf("Error; return code fro pthread_create is %d\n", ret);
    exit(-1);
  }
  ret=pthread_join(tid, NULL);
  if(ret){
    printf("Error; return code from pthread_join is %d\n", ret);
    exit(-1);
  }
  
  free(p);
}

/* sorting using two threads */
void *psort(void *param){
  Param p=*((Param *)param), *p1, *p2;
  int lo=p.lo, hi=p.hi, ret;
  int mid=(lo+hi)/2, *a=p.a;
  pthread_t tid1, tid2;
  pthread_attr_t attr;
  
  if(lo>=hi) return;
  
  if(hi-lo+1 <= size/4){
    sort_help(a, lo, hi);
    pthread_exit(0);
  }
  
  p1=(Param *)malloc(sizeof(Param));
  p2=(Param *)malloc(sizeof(Param));
  
  p1->a=a;  p1->lo=lo;  p1->hi=mid;
  p2->a=a;  p2->lo=mid+1;  p2->hi=hi;

  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
  ret=pthread_create(&tid1, &attr, psort, (void *)p1);
  if(ret){
    printf("Error; return code fro pthread_create is %d\n", ret);
    exit(-1);
  }
  ret=pthread_create(&tid2, &attr, psort, (void *)p2);
  if(ret){
    printf("Error; return code from pthread_create is %d\n", ret);
    exit(-1);
  }
  ret=pthread_join(tid1, NULL);
  if(ret){
    printf("Error; return code from pthread_join is %d\n", ret);
    exit(-1);
  }
  ret=pthread_join(tid2, NULL);
  if(ret){
    printf("Error; return code from pthread_join is %d\n", ret);
    exit(-1);
  }
 
  pmerge(a, lo, mid, hi);

  free(p1);
  free(p2);  
  pthread_exit(0);
}

/* sorting using sequential sort after the subarray size becomes 1/4th the original array */
void sort_help(int *a, int lo, int hi){
  int mid=(hi+lo)/2;

  if(lo>=hi) return;

  sort_help(a, lo, mid);
  sort_help(a, mid+1, hi);
  pmerge(a, lo, mid, hi);
}
  
/* merging of the sorted subarrays to get the sorted array*/
void pmerge(int *a, int lo, int mid, int hi){
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

