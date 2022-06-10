#ifndef __GETCH_H
  #include "../hdr/getch.h"
#endif
  
#ifndef __STDIO_H
  #include <stdio.h>
#endif

#define CHARBUFFLIMIT 128

static char buff[CHARBUFFLIMIT];
static char *buffp=buff;

char getch(){
  
  /* no buffer underflow */
  if(buffp==buff)
    return getchar();

  char res=*buffp;
  --buffp;
  return res;
}

int ungetch(char c){

  if( buffp-buff >= (CHARBUFFLIMIT-1) )
    return '\0'; /* buffer overflow */

  *buffp=c;
  ++buffp;
  return 1;

}
