#ifndef __GETCH_H
  #define __GETCH_H 1
#endif

/* getch: get a character from buffer or input */
char getch(void);

/* ungetch: put a character back into buffer */
int ungetch(char c);
