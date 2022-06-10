#include <stdio.h>
#define isgarbage(a) ( ( (a)>='!' && (a)<='/' ) || ( (a) >=':' && (a)<='@' ) || ( (a)<='.' && (a)>='[' ) || ( (a)>='{' && (a)<='~'  ) || (a)=='^' )
#define isnum(a) ( (a)>='0' && (a)<='9' )
#define isspace(a) ( (a)=='\n' || (a)=='\t' || (a)==' ' )

/* atoint: turns string into int */
int atoint(char *s){

  int i=0;

  while(isspace(*s))
    ++s;

  while(*s && isnum(*s)){
    i=(i*10) + (*s-'0');
    ++s;
  }
  
  return i;
}

/* prs: parses and prints a string in a nice way */
void prs(char *s,int newline){
  
  int nl=0;
  while(*s){

    /* formatting newline */
    if(nl==newline){
      putchar('\n');
      nl=0;
    }
    
    if(isgarbage(*s))
      printf("0X%x",*s);
    else 
      putchar(*s);
    ++nl;
    ++s;
  }
  
  putchar('\n');
}


int main(int argc,char **argv){
  
  /* parsing args */
  ++argv;
  int newl=10;
  if(**argv=='-' && (++*argv)){
    newl=atoint(*argv);
    if(newl<=0){
      fprintf(stderr,"flag should contain numerics! example: -10\n");
      return 1;
    }
    ++argv;
  }

  /* actual work */
  if(*argv && **argv)
    prs(*argv,newl);
  else{
    fprintf(stderr,"nice-input: no arguments given!\n");
    return 1;
  }

  return 0;
}
