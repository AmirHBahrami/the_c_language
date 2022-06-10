#include <stdio.h>

/*does str happen at the end of src?*/
int strnd_slfmd(char *str,char *src){
  
  /*remembering where str starts*/
  char *strstrt=str;

  /*same for src, to prevent errs*/
  char *srcstrt=src; 
  
  /*moving both pointers to their ends*/
  while(*str!='\0')str++;
  while(*src!='\0')src++;

  /*checking backwards*/
  while(str!=strstrt && src!=srcstrt){
    if(*str!=*src)
      return 0;
    str--;
    src--;
  }

  return 1;
}

int main(){
  
  printf("%d\n",strnd_slfmd("uck","holy fuck"));
  printf("%d\n",strnd_slfmd("asal","salam man asalam"));
  return 0;
}
