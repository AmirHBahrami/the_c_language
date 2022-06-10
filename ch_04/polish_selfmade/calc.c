#include "polish.h"

static int val[MAX_SIZE];
static int i; // to put (prepent/push)
static int j; // to get (dequeue)

// swaps the top two elements
void swapnum(void){
  int h=i;
  if(h==0)
    h+=2;
  int k=val[h-1];
  val[h-1]=val[h-2];
  val[h-2]=k;
}

// resets the state of the buffer
void clearnum(void){
  j=0;
  while(j<i){
    val[j]=0;
    j++;
  }
  i=0;
}

// note that dest should be big enough
void copynum(int dest[]){
  int k=0;
  while(k<i){
   dest[k]=val[k];
   k++;
  }
}

// a function mostly for debugging.
void printshit(void){
  int k=0;
  printf("len=%d ,arr=[ ",i);
  while(k<i)
    printf("%d,",val[k++]);
  printf("\b ]\n");
}

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

  #ifdef DEBUG_POPULATE
    printshit();
  #endif
}

int putnum(int n){
  if(i<MAX_SIZE){
    val[i++]=n;
	#ifdef DEBUG_POPULATE
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
    printf("[]->%d\n",val[j]);
	#endif
  return val[j++];
}

int peek(void ){

  return val[i-1];
}
