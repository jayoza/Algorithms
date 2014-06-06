#include<stdio.h>

int main(){
  int a[3]={1,3,2};
  int i;

  sort(a,3);

  for(i=0; i<3; i++)
    printf("%d ",a[i]);
  
  printf("\n");

  return 0;
}
