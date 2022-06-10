#ifndef __BUFF_DEF_H
  #include "../hdr/Buff.h"
#endif

#ifndef __BUFF_H
  #include "../hdr/buff.h"
#endif

#ifndef __CALC_C
  #include "../hdr/calc.h"
#endif

#ifndef BUFF_SIZE
  #define BUFF_SIZE 128
#endif

#ifndef __STDIO_H 
  #include <stdio.h>
#endif

#ifndef __STDLIB_H
  #include <stdlib.h>
#endif

void printh();

int main(int argc, char **argv){

  /* -c: calculate only one line (1); -f: read from file (2); -i, no flag : interactive (0)*/
  int m=0;
  FILE *f;
  ++argv;

  while(*argv){
    if(**argv=='-'){

      ++(*argv);
      switch(**argv){
        
        case 'f':
          m=2;
        break;
        
        case 'c':
          m=1;
        break;

        case 'i':
          m=0;
        break;
        
        case 'h':
          printh();
          exit(0);
        break;
        default:
          printh();
          exit(1);
        break;
      }
    }

    ++argv;
  }
  
  /* go back once, to get the last argument */
  --argv;

  switch(m){

    case 0: /* -i,interactive */
      c_rstd();
    break;

    case 1: /* -c */
      c_ralls(*argv);
    break;

    case 2: /* -f */
      f=fopen(*argv,"r");
      if(!ferror(f))
        c_rall(f);
      else {
        fprintf(stderr,"error: no such file/ file can't be read\n");
        exit(1);
      }
      fclose(f);
    break;

    default:
      fprintf(stderr,"error: wrong input.\n");
      exit(1);
    break;

  }
  
  printf("%d\n",c_eq());
  c_free();
  exit(0);
}

void printh(){
  
  /* -c: calculate only one line (1); -f: read from file (2); -i, no flag : interactive (0)*/
  printf("clc - usage: clc -[mode] [input]\nmodes:\n\t-c\tcalulate the argument\t;only calculates what is given as the next argument\n\t-f\tread from file\t\t;all the lines are calulated together\n\t-i\tinteractive\t\t;end input line by hitting enter\n");
  
}
