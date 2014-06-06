void sort(int *a, int size){
  int i, p, j;

  for(i=1; i<size; i++){
    p=a[i];
    j=i-1;
    while(j>=0 && a[j]>p){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=p;
  }
}
    
