#include "polish.h"

static char op[MAX_SIZE];
static int i;

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
  if(i>=0){
    if(op[i]=='\0') // IMPORTANT : if not,the pointer since the last time won't move
      i--;
    //printf("%c is just about to be returned with the code:%d\n",op[i],op[i]);
    return op[i--];
  }
  i=0; // bottom hit
  return '\0';
}

