#ifndef __IO_H
  #define __IO_H 1
  #define MAX_LINES 4096
  #define MAX_CHARS_PER_LINE 256
#endif 

#ifndef __STDIO_H
  #include <stdio.h>
#endif

/* readl: reads line from console and puts into buffer  */
int readl();

/* writel: prints all read lines */
void writel(int l);

/* getlen: get number of lines read */
int getlen();

/* getarr: get pointer to buffer */
char **getarr();
