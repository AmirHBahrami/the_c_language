#include <stdio.h>

/* copies src to the end of dst.dst should be big enough*/
void strcat_slfmd(char *src,char *dst){

  /*skip the unavailable*/
  while(*dst!='\0')
    dst++;
  
  /*copying the content*/
  while(*src !='\0'){
    *dst=*src;
    dst++;
    src++;
  }

}

/*copies maximum of n chars from src to end of dst.dst should be big enough*/
void strncat_slfmd(char *src,char *dst,int n){
  
  char *end=src;

  /*moving src pointer to max*/
  while(n>0 && *end!='\0'){
    end++;
    n--;
    printf("at:'%c',n:%i\n",*end,n);
  }
  
  /*signaling the end for strcat_slfmd*/
  *end='\0';

  /*sending the modified src to underlying strcat_slfmd*/
  strcat_slfmd(src,dst);
}

int main(){
  
  // NOTE : C99 standard: *src cannot be manipulated inside a function, src[] can!
  char src[32]=" in my name!";
  char dst[64]="I shall prevail";
  
  strncat_slfmd(src,dst,5);
  printf("%s\n",dst);

  return 0;
}
