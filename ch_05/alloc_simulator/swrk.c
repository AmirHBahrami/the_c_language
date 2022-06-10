#include "alloc.h"

// this file contains string operations merely here for testing.

// copy, dest should be big enough.
void scp(char dest[],char *src){
  int i=0;
  while(dest[i]!='\0' && src[i]!='\0'){
    dest[i]=src[i];
    i++; // don't be a hero!
  }
}

void print_diff(const char *s,const char *s1){
  int i=0;
  while(s[i]!='\0' && s1[i]!='\0'){
    if(s[i]==s1[i])
      printf("%c\v%c",s[i],s1[i]);
    else 
      printf("\'%c\'\v\'%c\'",s[i],s1[i]);
    i++;
  }
  printf("\v\n");
}
