#ifndef __TAIL_H
  #define __TAIL_H 1
#endif

#ifndef __STDIO_H
  #include <stdio.h>
#endif

#ifndef BUFF_SIZE
  #define BUFF_SIZE 1024
#endif

int putl(char *l);
char *getl();
void prtl(int,int);
