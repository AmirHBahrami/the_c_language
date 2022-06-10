#ifndef __QSORT_H
  #include "../headers/qsort.h"
#endif

#ifndef __STDIO_H
  #include <stdio.h>
#endif

#ifndef __STRING_H
  #include <string.h>
#endif

#ifndef __QSORT_C
  #define __QSORT_C 1
#endif

/* swaps two elements' memory addresses */
static void swap(void **arr,int i,int j){

  // char cpy[128];
  // strcpy((char *)arr[i],cpy);
  // void ***start=&arr;

  void *t=*(arr+i);
  // printf("*t='%s'\narr[i]='%s'\n",(char *)t,(char *)arr[i]);
  *(arr+i)=*(arr+j);
  *(arr+j)=t;
  
  // *start=arr;

  // printf("\t'%s'\n\t'%s'\n\n",(char*)arr[i],(char*)arr[j]);
}

void qsort(void *arr[],int length,int (*comp)(void *,void *)){

  int l=0,
      r=length-1,
      m=length/2,
      lc=m-1, // left-changer
      rc=m+1; // right-changer 

  while( l<r && lc!=0 && rc!=length-1 ){ // l-1 bc r moves
    
    // printf("line 1: '%s'\n",(char*)(arr[0]));

    /* comparing left */
    if((*comp)(arr[l],arr[m])>0){
      swap(arr,l,rc);
      ++rc;
    }
    
    /* comparing right */
    if((*comp)(arr[r],arr[m])<0){
      swap(arr,r,lc);
      --lc;
    }

    ++l;
    --r;
  }


}
