#ifndef __STRBUFF_H
  #define __STRBUFF_H 1
#endif

// static  char (*strs)[]; // array of pointers (strings)

/* putstr: puts an iniliased string in array */
int putstr(char *string);

/* putone: reads one line from inputstream */
int putone(char sep); // seperator

/* rall: reads inputstream until EOF */
void rall(char sep);

/* getstr: gets index i from array */
char *getstr(int i);

