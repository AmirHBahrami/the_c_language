#ifndef __CALC_H
  #include "../hdr/calc.h"
#endif

#ifndef __BUFF_DEF_H
  #include "../hdr/Buff.h"
#endif

#ifndef __BUFF_H
  #include "../hdr/buff.h"
#endif

#ifndef __CTYPE_H
  #include <ctype.h>
#endif

#ifndef __STDIO_H
  #include <stdio.h>
#endif

#ifndef BUFF_SIZE
  #define BUFF_SIZE 32
#endif

#define isnum(a) ( (a)>='0' && (a)<='9' )
#define issign(a) ( (a)=='+' || (a)=='-' || a=='/' || a=='*' || a=='%' )

static Buff *nb;
static Buff *sb;

static void init(){
  
  if(!nb)
    nb=buff_init(BUFF_SIZE);

  if(!sb)
    sb=buff_init(BUFF_SIZE);

}

void c_rall(FILE *f){

  if(!nb || !sb)
    init();

  int i;
  char c;
  
  /* skip whitespace && gibberish */
  while( (c=getc(f))!=EOF  && ( !isalnum(c) ));
  ungetc(c,f);
  
  /* reading input */
  while( (c=getc(f)) && c!=EOF && c!='\n'){
    
    /* adding to signs */
    if(issign(c)){
      bput(sb,c);
      continue;
    }

    /* adding to numbers*/
    else if(isnum(c)){
      i=0;
      while(isnum(c)){
        i= (i*10) + (c-'0');
        c=getc(f);
      }
      bput(nb,i);
    }

  }

}

void c_ralls(char *s){
  
  /* go to the end */
  char *sprim=s;
  while(*sprim)
    ++sprim;
  
  /* now push back in the correct order */
  while(sprim>=s){
    ungetc(*sprim,stdin);
    --sprim;
  }
  c_rstd();
}

int c_eq(){
  
  int i;
  char c;

  while((c=bget(sb))!='\0')
    switch(c){
      case '+':
        i=bget(nb);
        c=bget(nb); // temp
        bput(nb,i+c);
      break;

      case '-':
        i=bget(nb);
        c=bget(nb); // temp
        bput(nb,i-c);
      break;

      case '*':
        i=bget(nb);
        c=bget(nb); // temp
        bput(nb,i*c);
      break;

      case '/':
        i=bget(nb);
        c=bget(nb); // temp

        /* just defusing the bomb */
        if(c==0)
          c=1;
        bput(nb,i/c);
      break;

      case '%':
        i=bget(nb);
        bput(nb,i%bget(nb));
      break;

      defualt:break;
    }
  return bget(nb);
}

void c_free(){
  
  bfree(nb);
  bfree(sb);
}
