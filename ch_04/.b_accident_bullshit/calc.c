#include "polish.h"

static int val[MAX_SIZE];
static int i; // to put (prepent/push) 
static int j; // to get (dequeue)


#ifdef DEBUG
void printshit(void){
  int k=0;
  printf("len=%d ,arr=[ ",i);
  while(k<i)
    printf("%d,",val[k++]);
  printf("\b ]\n");
}
#endif

void prepnum(int n){
  
  int k=i;
  if(k==0)
    k=1;
  while(k>0){
    val[k]=val[k-1];
    k--;
  }

  val[0]=n;
  i++;

  #ifdef DEBUG
    printshit();
  #endif
}

int putnum(int n){
  if(i<MAX_SIZE){
    val[i++]=n;
	#ifdef DEBUG
    printf("[]<-%d \n",n);
    printshit();
	#endif
    return 0;
  }
  return 1;
}

int getnum(void){

  // WARNING : no input check for i == -1 or out of bound
	#ifdef DEBUG
    printf("[]->%d\n",val[j+1]);
	#endif
  return val[j++];
}
