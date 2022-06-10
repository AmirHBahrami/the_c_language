/**
 *  chapter 03, excercise 3:
 *  expands the shorthand notation of abc...xyz to all the characters in between.
 *  for ease of writing, the program uses a buffer and a buffer_counter with fixed sizes.
 *  note that there's no need to set the '\0' at the end of each buffer series, since
 *  the buffer itself is already initialised with '\0' elements at the beginning...
 * */
#define MAX_ARR_SIZE 1024
#define EXP_DOTS 3 // number of dots to mark the expansion 
#include <stdio.h>

static char buff[MAX_ARR_SIZE];
static int buff_counter=0;

int str_len(char[]);
void expand(char[]);

int main(void){
  
  char *str="a...j and so I was saying x...z";
  expand(str);
  printf("%s\n",buff);

  return 0;
}

int str_len(char str[]){
  
  int i=0;
  while(str[i]!='\0') i++;
  return i;

}

void expand(char str[]){
  
  int len=str_len(str);
  char before_dots=0;
  int dots_found=0;

  if(str[0]=='.')
    // todo : set errno
    return;

  for(int i=0;i<len;i++){
    
    #ifdef DEBUG
      printf("iteration:%d\n",i);
    #endif

    // first case of dot found.
    if(str[i]=='.'){
      
      #ifdef DEBUG
        printf("\tstr[%d]=='.'\n",i);
      #endif
      
      dots_found=0;
      for(int j=i;
        dots_found<=EXP_DOTS && str[j]=='.' && str[j]!='\0';
        j++,dots_found++);

      #ifdef DEBUG
        printf("\tnumber of dots found:%d\n",dots_found);
      #endif

      // number of initial dots less or more than the exp constant
      if(dots_found!=EXP_DOTS)
        break;

      #ifdef DEBUG
        printf("\tnot broken\n");
      #endif

      before_dots=str[i-1];
      for(int k=str[i+EXP_DOTS]; before_dots<k ;before_dots++)
        if(buff_counter<MAX_ARR_SIZE)
          buff[buff_counter++]=before_dots;
        else return; // the end of buffer reached.
      
      // jump to the next non-dot char in the original str
      i+=2;
      
    }

      else {
        
        // i was just lazy to adjust the whole fuckery, so here we go:
        // to avoid having the before_dots character be included twice
        if(str[i+1]!='.'){
          
          #ifdef DEBUG
            printf("else happened:str[%d]=%c\n",i,str[i]);
          #endif

          buff[buff_counter++]=str[i];
        }
      }
  }

}

