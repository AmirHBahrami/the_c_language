#include "polish.h"

#ifdef DEBUG_UTIL
  #include <stdlib.h>

  void printshit(void);
  void clearnum(void);
  void swapnum(void);
  void copynum(int src[]);
#endif

void prepnum(int n);
int putnum(int n);
int getnum(void);
int peek(void);

int putop(const char ch);
char getop();

void init_src(const char *ch);
char next_char();
int what_is(const char ch);

int main(int argc,char **argv){

  /*
  while(argc>0){
    printf("\t\'%s\'\n",argv[argc]);
    argc--;
  }
  */

  char *str="2 3 + 6 16 - \%  ";
  init_src(str);

  // init the operations and nums
  char c='\0',cp='\0'; // c-prev!
  int current_num=0; // will be updated in each iteration
  while((c=next_char())!='\0'){

    switch(what_is(c)){

      case IS_DIG:
        if(cp=='-'){

          // printf("\tminus\n");
          current_num-=(c-'0');
          break;
        }

        else {
          if(what_is(cp)==IS_DIG)
            current_num*=10;

          if(current_num<0)
            current_num-=(c-'0');
          else
            current_num+=(c-'0');
        }

      break;

      case IS_WS:
        // printf("IS_WS\n");
        switch(what_is(cp)){
          case IS_DIG:
            #ifdef DEBUG_PUT
              printf("\tnum added:%d\n",current_num);
            #endif
            putnum(current_num);
            current_num=0;
          break;
          case IS_SIGN:
          case IS_OP:
            #ifdef DEBUG_PUT
              printf("\toperation added:'%c'\n",cp);
            #endif
            putop(cp);
            current_num=0;
          break;
        }

      default:break;
    }
    #ifdef DEBUG_PUT
      printf("current_num:%d cp='%c' c='%c'\n",current_num,cp,c);
    #endif
    cp=c;
  }

  printf("%s",str);

  #ifdef DEBUG
    printf("\n");
  #endif

  // now operate based on what's read:
  int second=0;
  while((c=getop())!='\0'){
	#ifdef DEBUG
    printf("getop is %c\n",c);
	#endif
    switch(c){
      case '+':
        putnum(getnum()+getnum());
      break;
      case '-':
        putnum(getnum()-getnum());
      break;
      case '*':
        putnum(getnum()*getnum());
      break;
      case '/':
        putnum(getnum()/getnum());
      break;
      case '%':
        putnum(getnum()%getnum());
      break;
    }
  }

  printf(" = %d\n",peek());

  #ifdef DEBUG_UTIL
    printshit();
    swapnum();
    printshit();
    int wank[10];
    copynum(wank);
    printf("new wank:[ ");
    for(int i=0;i<10;i++)
      printf(" %d ,",wank[i]);
    printf("\b ]\n");
    clearnum();
    printshit();
  #endif

  return 0;
}
