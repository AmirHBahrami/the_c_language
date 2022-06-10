#ifndef __STRBUF_H
  #define __STRBUF_H 1
#endif

/* putstr: puts a particular string into buffer */
void putstr(char *);

/* rall: reads all the inputs and puts them into buffer */
void rall();

/* gets: gets one string from buffer in queue order */
char *gets();

/* clrbuf: clears buffer and resets it's state */
void clrbuf();
