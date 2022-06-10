#ifndef __STRBUFF_H
  #include "../hdr/strbuff.h"
#endif

#ifndef __WORD_BUFF_H
  #include "../hdr/word_buff.h"
#endif

#ifndef __STDIO_H
  #include <stdio.h>
#endif

#ifdef __DEBUG
  void printstr();
#endif

#ifdef __C_KW
/* K & R's c-keyword filtering done differently by me! */
static  char *kw[]={
    "for",
    "if",
    "do",
    "while",
    "char",
    "int",
    "sizeof",
    "struct",
    "void",
    "size_t",
    "FILE"
};
#endif

// TODO add the facility to tell which words are to be counted (through console with a flag, then csv,csv,...
int main( int argc, char (*argv)[]){
  
  #ifdef __C_KW
    rall_f(' ',kw); /* read all input (and filter them) */
  #else
    rall(' ');
  #endif
  
  #ifdef __DEBUG
    printstr();
  #endif

  /* retrieve and add them to word buffer */
  char *str;
  while(str=getstr())
    addw(str);
  

  /* TODO sort the array*/
  
  /* print words*/
  // BUG binsearch doesn't work
  printw();

}
