#include "polish.h"

void prepnum(int n);
int putnum(int n);
int getnum(void);

int putop(const char ch);
char getop();

void init_src(const char *ch);
char next_char();
int what_is(const char ch);

int main(int argc,char **argv){
  
  /*
  while(argc>0)
    printf("\t\'%s\'\n",argv[--argc]);
  */

  char *str="2 2 - 4 3 * +";
  init_src(str); 

  // idea for the question of adding signs in Kernighan and Ritchie's book:
  // int ws=0;
  // int sign=0; // no sign
  // while(...
  //  switch(
  //  case is_whitespace:
  //    ws=1;
  //  case is_op:
  //    if(ws)
  //      if(sign
  //        putnum('0'-c);
  //      else 
  //        putnum(0-('0'-c));
  //    else
  //      putop(c);
  //

  // init the operations and nums
  char c;
  while((c=next_char())!='\0'){
    switch(what_is(c)){
      case IS_DIG:
        //printf(" - a digit\n");
        prepnum(c-'0');
      break;
      case IS_OP:
        //printf(" - an operator\n");
        putop(c);
      break;
      case IS_SKIPPABLE:
      default:
        //printf(" - a bullshit\n");
      break;
    }

  }
  
  printf("%s",str);

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
        second=getnum();
        putnum(getnum()-second);
      break;
      case '*':
        putnum(getnum()*getnum());
      break;
      case '/':
        second=getnum();
        if(second==0)
          second=1; // defuse the bomb!
        putnum(getnum()/second);
      break;
    }
  }
  
  printf("\t= %d\n",getnum());
  return 0;

}
