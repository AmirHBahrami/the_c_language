#ifndef __IO_H
  #include "../headers/io.h"
#endif

#ifndef __STDIO_H
  #include <stdio.h>
#endif

#ifndef __STDLIB_H
  #include <stdlib.h>
#endif

#ifndef __IO_C
  #define __IO_C 1
#endif

/*
 *  big-bad-bug: if you read and save EOF as well in the buffer, when trying to 
 *  print all the lines, ALL the lines after EOF won't be printed and you might 
 *  end up being disappointed in life. 
 *
 *  Mind that qsort works fine, the internals of this file (io.c) and the main.c
 *  work fine, but you won't be able to SEE IT! and that causes pain. I spent three
 *  days thinking about the philosophy of life because of this little painful unimportant
 *  bug. god damn it! 
 *
 *  Still have this in mind too: the first order of initialisation could be right, and 
 *  so you print it, there's nothing wrong, but then you qsort it, and EOF string will 
 *  definitely change it's position , since it's first value is -1 , and that will record 
 *  less than anything even an empty string. Then when it's moved and you hit print, you
 *  cannot see all the steps in between. 
 *
 *  Also using a debugger is recommenbed in such scenarios.
 *
 *  +++++++++++++++++ LESSON LEARNED : NEVER SAVE EOF AS A VALID VALUE ++++++++++++++++++
 *
 *  --TAMAM!
 * */

static char *lines[MAX_LINES];
static char **lp=lines;

int readl(){

  /* for reading each line */
  *lp= (char *) malloc ( sizeof(char) * MAX_CHARS_PER_LINE);
  int i=0;
  while(i<MAX_CHARS_PER_LINE && ((*lp)[i]=getchar())!=EOF && (*lp)[i]!='\0' && (*lp)[i]!='\n')
    ++i;

  /* '\n' should not be a part of input read */
  if((*lp)[i]=='\n')
    (*lp)[i]='\0';

  /* saving result to return after ++lp*/
  if((*lp)[i]==EOF){
    (*lp)[i]='\0'; // defusing the big-bad-bug
    return 0;
  }

  ++lp;
  return 1;
}

void writel(int n){

  /* using the boolean variable to print line num*/
  if(n!=0)
    n=1; 

  lp=lines;
  while(*lp && **lp && lp-lines<MAX_LINES){
    if(n){
      printf("%d. %s\n",n,*lp);
      ++n;
    }
    else
      printf("%s\n",*lp);

    ++lp;
  }
}

int getlen(){
  return lp-lines;
}

char **getarr(){
  return &lines[0];
}
