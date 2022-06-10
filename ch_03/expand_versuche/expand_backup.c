#include <stdio.h>
#include <stdlib.h>

int str_len(const char *);
int three_dots_index(const char*);
int expand_len(const char *,int);
char *expand(const char *);

int main(int argc,char **argv){

  printf("%d\n",'f'-'4');
  //printf("%d\n",expand_len("fuck 4...f"));
  printf("%s\n",expand("hello shitty 4...f world!"));
  return 0;
};

int str_len(const char *str){
  
  int i=0;
  while(str[i])
    ++i;
  return i;

}

int three_dots_index(const char *str){

  int i=2;
  int dots=0;
  char last_not_dot=0;
  while(str[i+1]){
    
    if(str[i]=='.')
      dots++;
    
    else
      dots=0;
      //last_not_dot=str[i];

    if(dots==3)
      return i;
    
    i++;
   }
  return -1;
}

// we give the dude the last_three_index from outside, to save memory when in expand().
int expand_len(const char *str, int tdi){
  
  /**
   *  checks for the format %c...%c and also 
   *  checks if the second %c is greater that
   *  the former, because of the ansii-table 
   *  fuckery...
   *  then returns how many characters are 
   *  between them. aka. how many chars do
   *  we need to mallocate...
   * */

  //int tdi=three_dots_index(str);
  if(tdi==-1)
    return 0;
   
  else if(str[tdi-1] && str[tdi+1]>str[tdi-1])
     return str[tdi+1]-str[tdi-1];
  
  return 0; // if you want to use is to malloc, it shuouldn't make any problemns.
}

char *expand(const char *str){
  
  int len=str_len(str);
  int tdi=three_dots_index(str);
  char *res=(char *)malloc(sizeof(char)*(len+expand_len(str,tdi)+1));
  int i=0,res_counter=0,inner_i=0;;
  while(str[i]){
    //printf("str[%d]:%c\n",i,str[i]);
    if(i==(tdi-1)){
      inner_i=str[tdi-1];
      while(inner_i<str[tdi+1]){
        //printf("\tinner_i:%c,res[%d]:%c\n",inner_i,res_counter,res[res_counter]);
        res[res_counter]=inner_i;
        inner_i++;
        res_counter++;
      }
      i++;
      continue;
    }
    res[res_counter]=str[i];
    i++;
  }
  //printf("%s\n",res);
  return res;
}
