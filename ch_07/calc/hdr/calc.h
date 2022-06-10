#ifndef __CALC_H
  #define __CALC_H 1
#endif

#ifndef __STDIO_H
  #include <stdio.h>
#endif 

#define c_rstd() ( c_rall(stdin)  )

/* c_rall: reads all input from File */
void c_rall(FILE *f);

/* c_ralls: reads all input from a string */
void c_ralls(char *s);

/* c_eq: calculates one euqasion */
int c_eq();

/* c_free: frees the resources it has acquired*/
void c_free(void);
