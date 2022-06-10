#ifndef __BUFF_H
  #define __BUFF_H 1
#endif

#ifndef __BUFF_DEF_H
  #include "./Buff.h"
#endif

/* buff_init: makes a buffer object */
Buff *buff_init(int sz);

/* bput: adds a value to a buffer */
int bput(Buff *b,int val);

/* bget: gets a value from a buffer */
int bget(Buff *b);

/* bgeti: gets [i] th element of a buffer */
int bgeti(Buff *b,int i);

/* bfree: frees reources aquired for buffer */
void bfree(Buff *b);
