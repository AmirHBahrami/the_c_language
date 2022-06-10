#ifndef __READL_H
  #include "./readl.h"
#endif

#ifndef __READL_C
  #define __READL_C 1
#endif

static char line[LINE_SIZE];
static char *lp=line;

/* putch: puts a character in buffer */
static int putch(char c){
  
  if(lp-line>=LINE_SIZE)
    return 1;

  *lp=c;
  ++lp;
  
  return 0;
}

/* readl: reads a line from console and loads buffer */
int readl(char **ln_ptr){
  
  /* mark the start of the line */
  *ln_ptr=lp;

  int c;
  while((c=getchar())!='\0' && c!=EOF && c!='\n' && !putch(c))
    ;
  
  /* increase the pointer for marking the next line */
  ++lp;

  /* should the reading be done? (buffer full or EOF sent) */
  return lp-line < LINE_SIZE && c!='\0' && c!=EOF;
  
}

/* cll: clears the line input */
void cll(){

  while(lp!=line){
    *lp='\0';
    --lp;
  }
}
