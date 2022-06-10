#include <stdio.h>
#include <stdlib.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int numcmp(char *,char *);
void swap(void *v[],int i,int j);
void qu_sort(void *lp[],int l,int r,int (*comp)(void *,void *));

int main(){
  
  // mock data
  lineptr[0]="This is the first line.";
  lineptr[1]="Hello there, friend!";
  lineptr[2]="I am your QU , you are my slave";
  lineptr[3]="obey, and you shall be pardoned";
  lineptr[4]="obey not, and you have signed...";
  lineptr[5]="...the 'go fuck yourself' unlimited contract.";
  lineptr[6]="punkt.";
  qu_sort((void **)lineptr,0,6,(int (*)(void*,void*))(numcmp));
  for(int i=0;i<7;i++)
    printf("%d. %s\n",i,lineptr[i]);
  return 0;
}

int numcmp(char *s,char *s1){
  
  // skip the chars alike
  while(*s && *s1 && *s==*s1){
    ++s;
    ++s1;
  }

  return *s-*s1; //  0 : exactly the same

}

void swap(void *v[],int i,int j){

  void *temp=v[i];
  v[i]=v[j];
  v[j]=temp;
}

void qu_sort(void *v[],int l,int r,int (*comp)(void *,void *)){
    
  int i,last;
  if(l>=r)
    return;
  swap(v,l,(r+l)/2);
  last=l;
  for(i=l+1;i<=r;i++)
    if((*comp)(v[i],v[l])<0){
      ++last;
      swap(v,last,i);
    }
  swap(v,l,last);
  qu_sort(v,l,last-1,comp);
  qu_sort(v,last+1,r,comp);
}
