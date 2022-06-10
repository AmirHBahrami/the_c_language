#ifndef __TAIL_H
  #include "./tail.h"
#endif

#ifndef __TAIL_C
  #define __TAIL_C 1
#endif

static char *lines[BUFF_SIZE];
static char **lp=lines;

/* putl: puts a line and increments the pointer by 1 */
int putl(char *l){
  if(lp-lines>=BUFF_SIZE)
    return 1; // the last one should always be null
  *lp=l;
  lp++;

  return 0;
}

/* getl: retreives a line and decrements pointer by 1 */
char *getl(){
  if(lp==lines)
    return *lp;
  return *(--lp);
}

/* prtl: prints the last n lines of the buffer, linenum=0 means no line number */
void prtl(int n,int line_num){
  
  /* less than entriely read */
  if(lp-lines<n || n>=BUFF_SIZE)
    lp=lines;

  /* n is reasonable */
  else 
    lp-=n;

  int lnum=lp-lines+1; // number of starting lines 
  while(*lp){
    if(line_num){
      printf("%d.%s\n",lnum,*lp);
      lnum++;
    }
    else 
      printf("%s\n",*lp);
    lp++;
  }

}

