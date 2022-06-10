#ifndef __STRBUFF_H
  #define __STRBUFF_H 1
#endif

/* putstr: puts an iniliased string in array */
int putstr(char *string);


/* rall_f: reads inputstream until EOF with the option to filter the words */
void rall_f(char sep,char **filter_arr);

/* rall: reads inputstream until EOF */
void rall(char sep);

/* getstr: gets str from array's start on */
char *getstr();
