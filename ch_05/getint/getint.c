#ifndef _STDIO_H
  #include <stdio.h>
#endif

#ifndef _CTYPE_H
  #include <ctype.h>
#endif 

#ifndef _BUF_c
  #include "../../getch/getch.c"
#endif

#ifndef _GETINT_C
  #define _GETINT_C
#endif

/*get next integer from input into pn*/
int getint(int *pn){
  int c,sign;
  while(isspace(c=getch())) /*skip white space*/
    ;
  if(!isdigit(c) && c!=EOF && c!='+' && c!='-'){
    ungetch(c); // it's not a number
    return 0;
  }

  sign = (c=='-')? -1:1;

  /*line requested by excercise 5-1*/
  while(c=='+' || c=='-' || c==' ')
    c=getch();
  for(*pn=0; isdigit(c); c=getch())
    *pn=10 * (*pn) +(c-'0');
  *pn *= sign;
  if(c!=EOF)
    ungetch(c); // read too many chars
  return c;
}

/*get next float into pn*/
int getfloat(float *f){

  int i,c=0;
  float m=0.0f;

  /*reading the integer part*/
  c=getint(&i);
  *f=(float)i;

  /*does it have mantis?*/
  if((c=getch())=='.')
    c=getint(&i); // if so read it first
  
  /*mantis*/
  m=(float)i;
  while(m>1)
    m/=10;

  /*handle sign*/
  if(*f<0)
    *f-=m;
  else 
    *f+=m;
  return c;
}

int main(){
  ungetch('2');
  ungetch('1');
  ungetch('.');
  ungetch('8');
  ungetch(' ');
  ungetch('-');
  float pn=0;

  getfloat(&pn);
  printf("%4.2f\n",pn);
  return 0;
}
