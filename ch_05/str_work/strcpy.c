#include <stdio.h>

/*copies s to t's beginning.t should be big enough*/
void strcpy_slfmd(char *s,char *t){

  while(*s!='\0' && *t!='\0'){
    *t=*s;
    t++;
    s++;
  }

}

/*copies maximum n chars of s to t's beginning.t should be big enough,and s editable.*/
void strncpy_slfmd(char *s,char *t,int n){

  /*going n chars fwd in s*/
  char *end=s;
  while(n>0 && *end!='\0'){
    n--;
    end++;
  }

  /*marking s's end for strcpy_slfmd*/
  *end='\0';

  strcpy_slfmd(s,t);
}

int main(){
  char s[32]="your uncle maulus is in dc!";
  char t[64]="my uncle dave is in new orleans...";
  strncpy_slfmd(s,t,15); // a perefectly suited str for this cas ;)
  printf("%s\n",t);
  return 0;
}
