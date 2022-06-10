#ifndef __WORD_BUFF_H
  #define __WORD_BUFF_H 1
#endif 

/* made extern to emphasize that they are implemented in .c file */
extern struct word_struct;
extern struct word_struct words[];

/* addw: adds either new worsd or counts the old ones */
int addw(char *str);

/* printw: prints words */
void printw(void);
