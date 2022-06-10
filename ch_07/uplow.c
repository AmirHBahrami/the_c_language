#include <stdio.h>
#include <ctype.h>

int main(int argc,char **argv){
  
  /* determining which operation */
  ++argv;
  int op=0; /* 0: to lower , 1: to upper */
  if(**argv=='-'){
    ++(*argv);
    switch(**argv){
      case 'u':
        op=1;
        break;
      case 'l':
        op=0;
        break;
      default:
        break;
    }
  }
  
  /* parsing the argument */
  ++argv;
  if(!(**argv))
    return 1;
  while(**argv){
    if(op)
      putchar(toupper(**argv));
    else 
      putchar(tolower(**argv));
    ++(*argv);
  }
  putchar('\n');

  return 0;
}
