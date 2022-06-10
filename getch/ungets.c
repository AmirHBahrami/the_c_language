#ifndef _STDIO_H
  #include <stdio.h>
#endif

#ifndef _BUFP_C
  #include "./getch.c"
#endif

#ifndef _UNGETS_C
  #define _UNGETS_C
#endif

/* ungets a string */
void ungets(char *s){
  while(*s){
    ungetch(*s);
    s++;
  }
}

/* ungets a string reversely */
void ungetsr(char *s){
  
  // move to the end
  char *first=s;
  while(*s)
    s++;
  
  while(s!=first){
    --s;
    ungetch(*s);
  }

}
