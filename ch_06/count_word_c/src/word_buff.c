#ifndef __WORD_BUFF_H
  #include "../hdr/word_buff.h"
#endif

#ifndef __STDLIB_H
  #include <stdlib.h>
#endif

#ifndef __STRING_H
  #include <string.h>
#endif

#ifndef __STDIO_H
  #include <stdio.h>
#endif

#define MAX_WORD_STRUCTS 256

struct word_struct{
  int count;
  char *str;
};

struct word_struct words[MAX_WORD_STRUCTS];
struct word_struct *wp=words;
static int sorted=0;

/* findw: finds an element with binary search */
static struct word_struct *findw(char *str){

  /* using binsearch doesn't work, because the array isn't sorted yet! */
  for(struct word_struct *ws=words; ws!=wp; ws++)
    if(strcmp(str,ws->str)==0)
      return ws;
  return NULL;
}

static void sort(){ /* for now, some bubble sort placeholder */
  
  if(sorted) // double checking won't hurt
    return;
   
  /* find maximum - O(n^2) or something: find the max in each round and set it 
   * to the start element of that round then move start by one*/
  struct word_struct *start=words, *temp = (struct word_struct*) malloc (sizeof (struct word_struct)) ;
  int changed=0; // a lazy shortcut for telling the loop to start from head 
  while( start!=wp && *(start->str) && *(start->str) != EOF  ){
    for( struct word_struct *current=start; current!=wp && *(current->str); current++){
      if(strcmp(current->str,start->str)<0){ 
        *temp=*start;
        *start=*current;
        *current=*temp;
        changed=1;
        break;
      }
    }
    if(changed){
      start=words; // go back to beginning
      changed=0;
    }
    else
      ++start; // not safe: if current==start && *current changes, some dangerous shit might happen 
  }

  sorted=1;
}

int addw(char *str){
  
  if( wp-words > MAX_WORD_STRUCTS)
    return 0; /* to signal stop */
  
  struct word_struct *ws;
  
  /* if found increment count */
  if( (ws=findw(str))!=NULL ){
    ws->count++;
    return 1;
  }
  
  /* otherwise move current pointer */
  wp->str=str;
  wp->count=1;
  ++wp;
  sorted=0; // so that if anything added later, the fucker knows it's not sorted
  
  return 1; /* and returning 0 means all is fucked */
}

void printw(void){
  
  if(!sorted) // to prevent a new stack frame
    sort();
  
  struct word_struct *ws=words;
  while(ws!=wp){
    printf("%s\t%d\n",ws->str,ws->count);
    ws++;
  }
}

