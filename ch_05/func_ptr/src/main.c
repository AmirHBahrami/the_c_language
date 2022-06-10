#ifndef __STDIO_H
  #include <stdio.h>
#endif

#ifndef MAX_LINES
  #define MAX_LINES 4096
#endif

static char asc='a'; // order
static char type='s'; // datatype
static int (*ult_comp)(void*,void*); // will be determined based on use input

/* comps */
int strcomp(char *,char *);
int strcompcn(char *,char *);
int intcomp(int,int);
int floatcomp(float,float);

/* readl */
int readl();
void writel(int l);
int getlen();
char **getarr();

/* qsort */
void qsort(void *arr,int length,int (*comp)(void *,void *));

static void printhelp();
static int adsc();

/* linear qsort, therefore not much thought given only partially correct */
int main(int argc,char **argv){

  /* ------------------------------------------------------------------- */ 
  /* lined is not needed outside main, so not static */

  int lined=0; // print line number or not
  int cn=0; // case neutral

  ++argv; // skip program's name
  while(*argv){ // unless null pointer at the end is there
    switch(**argv){
      case '-':
        ++*argv; // the next character (still in the same space area)
        switch(**argv){
          
          case 'o':  // wanted to set flag o
            ++argv;  // therefore the next *argv[0] is the o's value
            if(**argv!='a' && **argv!='d'){
              printhelp();
              return 1;
            }
            asc=**argv;
          break;

          case 'n': cn   =  1 ; break;
          case 'i': type = 'i'; break;
          case 'f': type = 'f'; break;
          case 's':
          default : type = 's'; break;
        }
      break;
      default:break;
    }

    ++argv;
  }
  
  /* ------------------------------------------------------------------- */ 
  /* which function should be used for comparison */
  switch(type){

    case 'i':
      ult_comp= ( int (*)(void *,void *))intcomp;
    break;

    case 'f':
      ult_comp= ( int (*)(void *,void *))floatcomp;
    break;
  
    case 's':
    default:
      if(cn)
        ult_comp= ( int (*)(void *,void *))strcompcn;
      else 
        ult_comp= ( int (*)(void *,void *))strcomp;
    break;
  }

  /* ------------------------------------------------------------------- */ 
  /* begin reading the lines */
  
  while(readl()); // 1 == !EOF (read readl.c file)
  qsort((void **)getarr(),getlen(),adsc);
  writel(1);

  return 0;
}

/* ------------------------------------------------------------------- */ 
/* asdc: compares args in expected ascedning order */
static int adsc(void *a,void *a1){

  switch(type){ 

    case 'i':
    case 'f':
      printf(" i and f not supported yet");
    break;
  
    case 's':
      if(asc=='a')
        return (*ult_comp)(a,a1);
      else 
        return (-1 *(*ult_comp)(a,a1));
    default:
    break;
  }
}

/* ------------------------------------------------------------------- */ 
/* printhelp: prints the usage guide */
static void printhelp(){
  printf("usage: qsrt -[s|i|f]  [-n] [-l] (show line numbers or not) [-o [a|d] ]\n");
  printf("-n:case-neutral -l:print line numbers s:string i:int f:float a:ascending d:descending\n");
}
