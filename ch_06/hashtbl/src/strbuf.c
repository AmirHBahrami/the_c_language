#ifndef __STRBUF_H
  #include "../hdr/strbuf.h"
#endif

#ifndef MAX_STRS
  #define MAX_STRS 512
#endif

#ifndef MAX_STR_SIZE
  #define MAX_STR_SIZE 32
#endif

#ifndef __STRING_H
  #include <string.h>
#endif

#ifndef __STDLIB_H
  #include <stdlib.h>
#endif

#ifndef __STDIO_H
  #include <stdio.h>
#endif

#ifndef __CTYPE_H
  #include <ctype.h>
#endif

static char *buff[MAX_STRS];
static char **bp=buff;
static char **rdr=buff; /* queue reader */

void putstr(char *s){
  
  if(bp-buff >= MAX_STRS || !s)
    return;

  *bp=s;
  ++bp;

}

/* rone: reads exactly one input */
static int rone(){
  
  char *new=(char *)malloc(sizeof(char) * MAX_STR_SIZE);
  char *start=new;
  char c;
  
  while((c=getchar())!=EOF && !isspace(c) &&  (isalnum(c) ||c=='#' ||c=='_') && (new-start) < MAX_STR_SIZE){
    *new=c;
    ++new;
  }
  *new='\0';
  
  if(!start || !(*start) )
    free(start); // free the entirety
  
  else{

    // printf("rone:'%s'\n",start);
    putstr(start);
  }
  
  return c!=EOF;
}

void rall(){
  while(rone());
}

char *gets(){
  
  if(rdr==bp)
    return NULL;

  char *res=*rdr;
  ++rdr;

  // printf("'%s' about to return\n",res);

  return res;

}

void clrbuf(){
  
  if(bp==buff)
    return;

  --bp;
  while(bp!=buff && *bp)
    free(*bp);
  
  rdr=buff;
}
