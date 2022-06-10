#include <stdio.h>

/*self-made! compares the beginning of two strs lexico-graphically.*/
int strcmp_ich(char *s,char *t){

  while(*s!='\0' && *t!='\0' && *t==*s){
    s++;
    t++;
  }
  
  /*if you set a limit, the last character before '\0' is to be compared*/
  if(*s=='\0' && *t!='\0') // there's still caveats in this
    s--; 
  
  return *s-*t;
}

/*compares only n chars of s's beginning to t's beginning.*/
int strncmp_ich(char *s,char *t,int n){

  char dflt=0; // remembering the char to change 
  
  /*skipping the first n chars*/
  char *end=s;
  while(*end!='\0' && n>0){
    end++;
    n--;
  }
  dflt=*end;

  /*marking the stopping point for strcmp_ich*/
  *end='\0';
  int result=strcmp_ich(s,t);
  *end=dflt; // undoing the change 

  return result;
}

int main(){

  char s[32]="This is how democracy dies.";
  char t[32]="This is how to poop wishes.";
  
  printf("first %d chars : %d\n",5,strncmp_ich(s,t,5));
  printf("first %d chars : %d\n",2,strncmp_ich(s,t,2));
  return 0;

}
