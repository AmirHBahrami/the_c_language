#include "polish.h"

static char src[MAX_SIZE]; // has the entire line entered by user
static int i;

void init_src(const char *ch){

  int j=0;
  while(ch[j]!='\0' && i<MAX_SIZE)
    src[i++]=ch[j++];
  i--; // IMPORTANT: if not, the first next_char returns the last char , aka '\0'
}

char next_char(){
  if(i>=0)
    return src[i--];

  // TODO : free the i and src here
  return '\0';
}

int what_is(const char ch){
  //printf("what is %c?",ch);
  if(ch >= '0' && ch <='9')
    return IS_DIG;
  else if(ch=='+' || ch=='*' || ch=='-' || ch=='/')
    return IS_OP;
  else 
    return IS_SKIPPABLE;
}
