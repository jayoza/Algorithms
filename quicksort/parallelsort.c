#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

struct param{
  int *a;
  int lo;
  int hi;
};

typedef struct param Param;

void sort(int *, int , int);
int partition(int *, int, int);
void swap(int *, int *);
void *pquicksort(void *);

void quicksort(int *a, int sz){
  int count;
  pthread_t tid;
  pthread_attr_t attr;
  Param *p;

  p=(Param *)malloc(sizeof(Param));
  
  p->a=a;
  p->lo=0;
  p->hi=sz-1;

  pthread_attr_init(&attr);
  pthread_create(&tid, &attr, pquicksort, (void *)p);
  pthread_join(tid, NULL);
}

void *pquicksort(void *param){
  Param p=*((Param *)param), *p1, *p2;
  int i;
  pthread_t tid1, tid2;
  pthread_attr_t attr;

  if(p.lo>=p.hi){
    return;
  }

  if(p.hi-p.lo+1<=12500){
    sort(p.a, p.lo, p.hi);
    pthread_exit(0);
  }

  p1=(Param *)malloc(sizeof(Param));
  p2=(Param *)malloc(sizeof(Param));
  
  i=partition(p.a, p.lo, p.hi);
  p1->a=p.a; p1->lo=p.lo; p1->hi=i-1;
  p2->a=p.a; p2->lo=i+1; p2->hi=p.hi;
  
  pthread_attr_init(&attr);
  pthread_create(&tid1, &attr, pquicksort, (void *)p1);
  pthread_create(&tid2, &attr, pquicksort, (void *)p2);
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);

  free(p1);
  free(p2);
  pthread_exit(0);
}

void sort(int *a, int lo, int hi){
  int p;
 
  if(hi<=lo) return;

  p=partition(a, lo, hi);
  sort(a, lo, p-1);
  sort(a, p+1, hi);
}

int partition(int *a, int lo, int hi){
  int pivot, temp, median;
  int i=lo+1, j, p;
  int mid=(hi+lo)/2;

  pivot=a[lo];

  for(j=lo+1; j<=hi; j++){
    if(a[j]<=pivot){
      swap(&a[i], &a[j]);
      i++;
    }
  }
 
  swap(&a[i-1], &a[lo]);

  return i-1;
}
  
void swap(int *i, int *j){
  int temp;
  
  temp=*i;
  *i=*j;
  *j=temp;
}
