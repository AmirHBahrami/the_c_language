#ifndef __POLISH_H
  #include "./polish.h"
#endif

#ifndef __PNUMQ_C
  #define __PNUMQ_C 1
#endif

static int queue[MAX_BUFF_SIZE];
static int *qp=queue;

/* getint: gets an integer from the queue */
int getint(){

  if(qp<queue)
    qp=queue;
  
  return *(--qp);
}

/* putint: puts and integer into the queue */
void putint(int i){
  if(qp-queue >= MAX_BUFF_SIZE){
    printf("int buffer full, aborted.\n");
    return;
  }
  
  *qp=i;
  qp++;
}

/* peekint: returns the current pointer's value without removing it */
int peekint(){
  return *qp;
}

/* resiq: empties the queue of values and resets the pointer */
void resiq(){

  while(qp!=queue){
    *qp=0;
    --qp;
  }
}

#ifdef DEBUG 
void printints(){
  int *start=queue;
  while(start!=qp){
    printf("%ld:%d\n",start-queue,*start);
    start++;
  }
  printf("%ld:%d\n",start-queue,*start);
}
#endif
