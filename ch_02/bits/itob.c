/**
 *  gets dec int returns string in base b
 * */
#include <stdio.h>

int str_len(const char *str);
void itob(int i,int b,char str[]);

int str_len(const char *str){
  int i=0;
  while(str[i]!='\0')
    ++i;
  return i;
}

// mutates str + also handles b>0
void itob(int i,int b,char str[]){
  
  int negated=0;

  if(i<0){
    i*=-1;
    i+=1;
    negated=1;
  }

  int str_counter=str_len(str)-1; // start from last index
  int current=-1;
  for(;i>0 && b>0 && str_counter>0;i/=b){
    current=(i%b);
    if(current>=10){ // only happens if b>0
      current-=10;
      current+='a';
    }
    else 
      current+='0';
    str[str_counter]= current ;
    str_counter--;
  }
  
  // putting white spaces at the back of the string
  while(str_counter>=0)
    str[str_counter--]='-';

  if(negated)
    str[0]='1';
}
