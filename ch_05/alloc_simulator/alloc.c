#include "alloc.h"

static char buff[INITIAL_BUFF_SIZE];
static int last_index;
static char *fp=&buff[0];

void psoa(void){
  int i=0;
  printf("[");
  while (i<last_index){
    printf("%c,",buff[i]=='\0'?'|':buff[i]);
    i++; 
  }
  printf("\b]\tfp-1:%c\tlast_index:%i\n",*(fp-1),last_index);
}

// n should include the '\0' at the end
char *alloc(int n){

  if(last_index+n>=INITIAL_BUFF_SIZE)
    n=INITIAL_BUFF_SIZE - last_index;

  char *start_p=fp;
  int start=last_index; 
  
  // un-endifying (setting to anything other than '\0')
  while(start<=(last_index+n)){
    buff[start]='-';
    start++;
  }
  
  fp+=n;

  // marking the end to avoid confusion after
  // muliple alloc/free calls
  *fp='\0'; 
  fp++;

  last_index=start;
  #ifdef D_ALLOC
    psoa();
  #endif
  return start_p;
}

char *afree(void ){
  /* frees the last allocated array and re-inits it with default '\0'
   * returns a pointer to the last element released (freed) to compare
   * if an error occurs, returns 1.
   * */

  if(last_index==1){
    last_index--;
    fp--;
  }
  
  if (last_index == 0) 
    return fp;

  fp-=2;
  while(((*fp)!='\0')){
    #ifdef D_ALLOC
      printf("afree:we're at %c\n",*fp);
    #endif
    *fp='\0';
    fp--;
    last_index--;
  }

  #ifdef D_ALLOC
    psoa();
  #endif  
  return fp+1; // return where the last pointer is supposed to be
}

