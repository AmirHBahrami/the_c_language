#ifndef __WORD_STRUCT_H
  #include "../hdr/word_struct.h"
#endif

#ifndef __STDLIB_H
  #include <stdlib.h>
#endif

struct word{

  int count;
  char *str;
  struct word *next;
};

struct word *init_word(char *str){

  struct word *w=(struct word *) malloc (sizeof(struct word));
  
  w->str=str;
  w->count=0;
  w->next=NULL;

  return w;
}
