#ifndef _STDIO_H
  #include <stdio.h>
#endif

#ifndef _BUFP_C
  #define _BUFP_C
#endif 

#ifndef BUFFSIZE
  #define BUFSIZE 128
#endif

char buf[BUFSIZE];
char *bufp=buf;

char getch(void){
  
  if(bufp-buf<=0) // number of elements
    return '\0';

  char c=*(--bufp);
  return c;
}

void ungetch(char c){
  
  if(bufp-buf >= BUFSIZE)
    printf("err - ungetch: too many characters!\n");
  else {
    if(c==EOF)
      c='\0';
    *bufp=c;
    bufp++; // don't be a hero!
  }
  
}
