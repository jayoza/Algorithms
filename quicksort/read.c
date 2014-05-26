#include<stdio.h>

inline fastread(FILE *fp, int *a, int sz){
  char c = getc(fp);
  int j, i=0, flag=0, neg_flag=0;
  
  for(j=0; j<sz; j++){
    a[j]=0;
  }
    
  if(c==45) neg_flag=1;
  else if (c>=48 && c<58){
    a[0]=c-48;
  }
  else flag=1;

  while((c=getc(fp))!=EOF){
    if(c>=48 && c<58){
      flag=0;
      c=c-'0';
      a[i]= (a[i]<<3)+(a[i]<<1)+c;
    }
    else if(c==45){
      if(neg_flag==1){
	a[i]=-a[i];
	neg_flag=0;
      }else neg_flag=1;
      continue;
    }
    else if(flag==0){
      if(neg_flag==1){
	a[i]=-a[i];
	neg_flag=0;
      }
      i++;
      flag=1;
      continue;
    }
  }
}
