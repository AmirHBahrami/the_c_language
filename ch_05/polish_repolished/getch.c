#ifndef _POLISH_H
  #include "./polish.h"
#endif

#ifndef __PGETCH_C
  #define __PGETCH_C 1
#endif

/* queue: to save operations' order */
static char buff[MAX_BUFF_SIZE];
static char *buffp=buff; // putter
static char *buffg=buff; // getter

/* ungetch: puts a character in the buffer*/
void ungetch(char c){
   
  if(buffp-buff==MAX_BUFF_SIZE){
    // ungetc(c); 
    return;
  }

  *buffp=c;
  ++buffp;
}

/* getch: retreives a character from the buffer */
char getch(){

  if(buffg==buffp)
    return '\0';

  char c=*buffg;
  buffg++;
  return c;
}

/* peekc: returns the upmost character */
char peekch(){
  return *buffp;
}

/* resch: empties the buffer and resets the pointer */
void resch(){
   
  while(buffp!=buff){
    *buffp='\0';
    --buffp;
  }
}
