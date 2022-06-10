#ifndef __BUFF_DEF_H
  #include "../hdr/Buff.h"
#endif

#ifndef __BUFF_H
  #include "../hdr/buff.h"
#endif

#ifndef __STDLIB_H
  #include <stdlib.h>
#endif

#define bqend(b) ( (b)->rdr==(b)->bufp )

Buff *buff_init(int sz){
 
  Buff *b=(Buff *)malloc(sizeof(Buff));
  b->buff= (int *)malloc(sizeof(int)*sz);
  b->sz=sz;

  /* setting interactive pointers */
  b->bufp=b->buff;
  b->rdr=b->buff;
  
  return b;
}

int bput(Buff *b,int val){
  
  if(((b->bufp)-(b->buff))>=b->sz)
    return 0; /* we take 0 inside a program for failure */
  
  *(b->bufp)=val;
  ++(b->bufp);
  return 1;
}

int bget(Buff *b){
  
  if (b->rdr==b->bufp)
    return 0; 

  int val=*(b->rdr);
  ++(b->rdr);

  return val;
}

int bgeti(Buff *b,int i){
  
  if(i<0)
    i=0;
  else if(i>=b->sz)
    i=(b->sz)-1;

   return b->buff[i];
}

void bfree(Buff *b){
  
  free(b->buff);
  b->sz=0;
  free(b);
}
