#ifndef __WORD_BUFF_H
  #include "../hdr/word_buff.h"
#endif

#ifndef __STDLIB_H
  #include <stdlib.h>
#endif

#ifndef __STRING_H
  #include <string.h>
#endif

#define MAX_WORD_STRUCTS 256

struct word_struct{
  int count;
  char *str;
};

struct word_struct words[MAX_WORD_STRUCTS];
struct word_struct *wp=words;

/* uses binary search to find an element */
static word_struct *findw(char *str){
  
  struct word_struct start=words,end=wp,mid;
  int comp;
  while(start-end<0){
    mid=&(words[(end-start) /2]);
    if( (comp=strcmp(start->str,mid->str)) > 0 )
      start=mid+1;
    else if( comp <0)
      end=mid;
    else 
      return mid;
  }
  return NULL;
}

int addw(char *str){
  if( wp-words >= MAX_WORD_STRUCTS)
    return 1; /* based on conventions in c , returning 1 means error*/

  struct word_struct *new;

  /* if not found */
  if( (new=findw(str))!=NULL ){
      new=(struct word_struct *) malloc(sizeof(struct word_struct));
      ++(new->count);
  }
  else {

    new->str=str;
    new->count=0;
  }


  wp=&(*new); // getting the address of what new is pointing at (in a kind of a weird way!)
  ++wp;

  return 0; /* and returning 0 means all is perfect */
}
