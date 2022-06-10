#ifndef __WORDTAB_H
  #define __WORDTAB_H 1
#endif

#ifndef __WORD_STRUCT_H
  #include "./word_struct.h"
#endif

/* binsearch: finds a word's pointer in wordtab */
  struct word *binsearch(char *str);

/* printw: prints whole array's report */
void printw(){}
