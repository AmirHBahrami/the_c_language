#include <stdio.h>
#include <stdlib.h>

int str_len(const char *);
int three_dots_index(const char*,int);
int expand_len(const char *,int);
int *expand_len_arr(const char*,int);
char *expand(const char *);

int main(int argc,char **argv){

  printf("%d\n",'f'-'4');
  //printf("%d\n",expand_len("fuck 4...f"));
  printf("%s\n",expand("hello mr. 1...3 black 4...8 addar 9...f world!"));
  return 0;
};

int str_len(const char *str){
  
  int i=0;
  while(str[i])
    ++i;
  return i;

}

int three_dots_index(const char *str,int starter_index){

  int i=starter_index<2?2:starter_index;
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

// getting len from outside to reduec the resource fuckery.
int *expand_len_arr(const char *str,int len){

  int *res=(int *)malloc(sizeof(int)*len); // bc at least...
  int i=2,res_counter=0;;
  int index=-9; // just a safe beginning rvalue.
  while(i<len){
    index=three_dots_index(str,i);
    if(index>0)
      res[res_counter]=index;
    i+=3;
  }

  res[i]=-1; // indicator that the array ends. (it works in our case).
  return res;
}

char *expand(const char *str){
  
  int len=str_len(str);
  int *tdarr=expand_len_arr(str,len);
  int three_dots_size=0;
  int i=0;
  while(tdarr[i]!=-1){
    three_dots_size+=expand_len(str,tdarr[i]);
    i++;
  }
  
  char *res=(char *)malloc(sizeof(char)*(len+three_dots_size+1));
  int res_counter=0,inner_i=0;
  int tdi=tdarr[0],tdi_counter=0;;
  i=0;
  while(str[i]){
    //printf("str[%d]:%c\n",i,str[i]);
    tdi=tdarr[tdi_counter];
    if(i==(tdi-1)){
      inner_i=str[tdi-1];
      while(inner_i<str[tdi+1]){
        //printf("\tinner_i:%c,res[%d]:%c\n",inner_i,res_counter,res[res_counter]);
        res[res_counter]=inner_i;
        inner_i++;
        res_counter++;
      }
      i++;
      tdi_counter++;
      continue;
    }
    res[res_counter]=str[i];
    i++;
  }
  //printf("%s\n",res);
  return res;
}
