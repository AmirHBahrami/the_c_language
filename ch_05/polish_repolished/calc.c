#ifndef __POLISH_H
  #include "./polish.h"
#endif

#ifndef __CALC_C
  #define __CALC_C 1
#endif

char getch();

int getint();
void putint(int i);

/* calc: processes numbers and signs from buffers until no sign remaining */
int calc(){
  
  int prev,mqs; // maqsumonelaih!
  char c;
  while((c=getch())!='\0'){

    prev=getint();
    mqs=getint();
    switch(c){

      case '+':
        printf("%d+%d\n",prev,mqs);
        putint(prev+mqs);
      break;

      case '-':
        printf("%d-%d\n",prev,mqs);
        putint(prev-mqs);
      break;

      case '/':
        
        // defusing the bomb!
        if(mqs==0)
          mqs=1;

        printf("%d/%d\n",prev,mqs);
        putint(prev/mqs);
        break;
        
       case '*':
       case 'x':
        printf("%d*%d\n",prev,mqs);
        putint(prev*mqs);
       break;

       case '%':
        printf("%d mod %d\n",prev,mqs);
        putint(prev%mqs);
       break;
    }

  }

  return getint(); 
}
