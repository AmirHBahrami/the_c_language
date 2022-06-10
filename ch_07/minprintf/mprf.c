#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>
#define isnum(a) ( (a)<='9' && (a)>='0' )


/* minprintf: minial printf with variable argument list */
void minprintf(char *fmt,...){
  
  va_list ap;
  char *p,*sval;
  int ival,offset=0,offset1=0,strl=0;
  int *offp=&offset; /* bc reading offsets should be switched */
  double dval;

  va_start(ap,fmt);
  for(p=fmt;*p; p++){
    if(*p != '%' ) {
      putchar(*p);
      continue;
    }

    ++p;
    
    
    /* adding offset support */
    do{

      /* if there's a dot, start at the second offset */
      if(*p=='.'){
        offset=0;
        offp=&offset1;
        ++p;
      }
      
      *offp= ((*offp) *10) + (*p-'0');
      ++p;

    }while(isnum(*p) || *p=='.');
    // printf(" [%d.%d] ",offset,offset1);

    /* embedding the arguments */
    switch(*p){

      case 'd':
        ival=va_arg(ap,int);
        printf("%*.*d",offset,offset1,ival);

      break;
      
      case 'f':
        dval=va_arg(ap,double);
        printf("%*.*f",offset,offset1,dval);
      break;

      case 's':
        
        offset1=0;
        for(sval= va_arg(ap,char *); *sval; sval++){
          putchar(*sval); 
          ++offset1;
        }
        
        /* filling the remaining offset */
        while(offset1<offset){
          putchar(' ');
          ++offset1;
        }

      break;

      default:break;
    }

    /* resetting offsets */
    offset=offset1=0;
    offp=&offset;
    
  }


  va_end(ap);

}



int main(){
 
  /* showcasing the default behaviour */
  printf("%-5d %3.2f %1.3s\n",555,1.44444444444444,"hello_bitches");
  minprintf("start %.7d %3.2f %16s end. ",15,4.2131313131,"bye ta hi|");
  putchar('\n');

  return 0;
}
