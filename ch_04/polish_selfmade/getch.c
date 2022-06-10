#include "polish.h"

static char op[MAX_SIZE];
static int i;
static int j;

int putop(const char ch){ // returns 1 for failure
  
  //printf("\"The code to \\0 is %d\n\"",'\0');
  if(i<MAX_SIZE){
    op[i++]=ch;
    //printf("%c has just been put to shit with the code:%d\n",ch,ch);
    return 0;
  }
  return 1;
}

char getop(){ // returns -1 if empty
  if(j<i)
    return op[j++];
  j=0;
  i=0; // bottom hit
  return '\0';
}

