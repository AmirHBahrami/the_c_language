#ifndef __STRBUFF_H
  #include "../hdr/strbuff.h"
#endif

#ifndef __STDLIB_H
  #include <stdlib.h>
#endif

#define STRS_CAP 64
#define MAX_STR_LEN 128

static char (*strs)[STR_CAP]; // array of pointers
static char **sp=strs;

int putstr(char *s){

  if( sp-strs >= STR_CAP){
    *sp=NULL;
    return 0; // no more space
  }
  
  *sp=s;
  ++sp;
  return 1;
}

int putone(char sep){

  char *new=(char *) malloc ((sizeof(char))*MAX_STR_LEN);

  char c; /* save read char from inputstream */
  char *start=new;  /* to check for limit */

  /* read until next seperator or EOF */
  while((c=getchar())!=sep && c!=EOF && (new-start) < MAX_STR_LEN )
    *new=c;
  *new='\0';
  return putstr(start) && c==EOF; /* reading process */
}

void rall(char sep){
  while(putone(sep))
    ;
}

char *getstr(int i){
  if( i<0 || (sp+i) < STR_CAP )
   return NULL; 
  return strs[i];
}
