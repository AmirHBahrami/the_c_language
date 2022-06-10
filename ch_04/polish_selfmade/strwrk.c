#include "polish.h"

static char src[MAX_SIZE]; // has the entire line entered by user
static int i;
static int j;

void init_src(const char *ch){

  int j=0;
  while(ch[j]!='\0' && i<MAX_SIZE)
    src[i++]=ch[j++];
  i--; // IMPORTANT: if not, the first next_char returns the last char , aka '\0'
}

char next_char(){
  if(j<i)
    return src[j++];

  // TODO : free the i and src here
  /*
  free(i);
  free(j);
  free(src);
  */
  return '\0';
}

int what_is(const char ch){
  // printf("what is %c?\n",ch);
  if(ch >= '0' && ch <='9')
    return IS_DIG;
  else if (ch==' ')
    return IS_WS;
  else if (ch=='-' || ch=='+')
    return IS_SIGN;
  else if(ch=='*' || ch=='/' || ch=='%')
    return IS_OP;
  else
    return IS_SKIPPABLE;
}
