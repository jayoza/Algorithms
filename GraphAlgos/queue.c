#include<stdio.h>
#define SZ 100000

int queue[SZ];
int tail=0, head=0;

void enqueue(int node){
  if((tail+1)%SZ==head){
    fprintf(stderr,"[ERROR] : Queue Overflow!\n");
    return ;
  }
  queue[tail]=node;
  tail=(tail+1)%SZ;
}

int dequeue(){
  int value;
  if(isEmpty()){
    fprintf(stderr,"[ERROR] : Queue Underflow!\n");
    return -1;
  }
  value=queue[head];
  head=(head+1)%SZ;
  return value;
}

int isEmpty(){
  if(head==tail) return 1;
  else return 0;
}
