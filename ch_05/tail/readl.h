#ifndef __READL_H
  #define __READL_H 1
#endif

#ifndef __STDIO_H
  #include <stdio.h>
#endif

#ifndef LINE_SIZE
  #define LINE_SIZE 128
#endif

int readl(char **ln_ptr);
