#ifndef __STRBUFF_H
  #include "../hdr/strbuff.h"
#endif

#ifndef __STDLIB_H
  #include <stdlib.h>
#endif

#ifndef __STRING_H
  #include <string.h>
#endif

#ifndef __CTYPE_H
  #include <ctype.h>
#endif

#ifndef __STDIO_H
  #include <stdio.h>
#endif

#define STRS_CAP 64
#define MAX_STR_LEN 128

static char *strs[STRS_CAP]; // array of pointers
static char **sp=strs;
static char **reader=strs;

/* filter: you can pass a char ** from outside to filter input */
static int filter(char *str,char **filter_arr){
 
    if(!filter_arr || !(*filter_arr))
    return 1; /* no filters set => it's allowed */
  

  if(!(*str))
    return 0;
 
  // TODO make this asshole binsearch
  for(char **fl=filter_arr; fl && *fl && **fl; fl++)
    if(strcmp(*fl,str)==0)
      return 1;
  return 0;

}


int putstr(char *s){

  if( sp-strs >= STRS_CAP){
    *sp=NULL;
    return 0; // no more space
  }

  else if(!s)
    return 0;
  
  *sp=s;
  ++sp;
  return 1;
}


/* putone: reads one string to put in buffer */
static int putone(char sep,char **filter_arr){

  char *new=(char *) malloc ((sizeof(char))*MAX_STR_LEN);

  char c; /* save read char from inputstream */
  char *start=new;  /* to check for limit */

  /* read until next seperator or EOF */
  /* MAX_STR_LEN-1 : last char --> free for '\0' */
  while((c=getchar())!=sep && c!='\0' && c!=EOF && (new-start) < ( MAX_STR_LEN - 1 ) && !isspace(c) && isalpha(c) ){
    *new=c;
    ++new;
  }
  *new='\0';
  
  /* filtering input */
  if( (filter_arr && !filter(start,filter_arr) ) || !*(start))
    free(start);
  else 
    putstr(start);
  
  /* it is filtered already */
  return c!=EOF ; /* reading process */
}


void rall_f(char sep,char **filter_arr){
  while(putone(sep,filter_arr))
    ;
}

void rall_s(char sep, char *str, int n){  

  /* read one word, but free it if it doesn't match str's n first chars */
  char *last;
  while(putone(sep,NULL)){
    
    /* nothing has been read, so the pointer hasn't moved yet */
    if(sp==strs)
      return;

    last=*(sp-1);
    for(int i=0;i<n;i++)
      if(last[i]!=str[i]){
        last=*sp;
        *sp=NULL;
        free(last);
        --sp;
        break;
      }
  }
  
}


void rall(char sep){
  rall_f(sep,NULL);
}



char *getstr(){
 
  /* essential for not returning nonesense */
  if(reader==sp)
    return NULL;

  char *res=*reader;
  ++reader;
  return res;
}
