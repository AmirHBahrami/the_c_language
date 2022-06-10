#ifndef __COMPS_H
  #include "../headers/comps.h"
#endif

#ifndef __STDIO_H
  #include <stdio.h>
#endif

#ifndef __STDLIB_H
  #include <stdlib.h>
#endif

#ifndef __COMPS_C
  #define __COMPS_C 1
#endif

/* lowerc: lowercases a character */
static char lowerc(char c){

  if(c<='Z' && c>='A')
    c-=('A'-'a');

  return c;
}

int strcomp(char *s, char *s1){

  /* NOTE: from void* to char* happens automatically in runtime */
  /* it's the same as internal int -> float typecast */
  
  while( *s && *s1 && *s==*s1){
    ++s;
    ++s1;
  }
  
  if(*s>*s1)
    return 1;
  else if(*s<*s1)
    return -1;
  return 0;
}

int strcompcn(char *s,char *s1){

  while(*s && *s1 && lowerc(*s)==lowerc(*s1)){
    ++s;
    ++s1;
  }

  if(*s>*s1)
    return 1;
  else if (*s<*s1)
    return -1;
  return 0;
}

int intcomp(int a,int b){
 
  if(a>b)
    return 1;
  else if (a<b)
    return -1;
  return 0;
}

int floatcomp(float a,float b){
  
  if(a>b)
    return 1;
  else if (a<b)
    return -1;
  return 0;
}  

