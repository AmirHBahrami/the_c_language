#ifndef __GETWORD_H
  #include "../hdr/getword.h"
#endif

#ifndef __GETCH_H
  #include "../hdr/getch.h"
#endif

#ifndef __STDIO_H
  #include <stdio.h>
#endif

#ifndef __CTYPE_H
  #include <ctype.h>
#endif

int getword(char *word,int lim){

  int c,cmnt; // is comment?
  char *w=word;
  
  /* skip whitespace*/
  while(isspace(c=getch()));

  if(c!=EOF){
    *w=c;
    w++; // don't be a hero!
  }

  if(!isalpha(c)){
    *w='\0';
    return c;
  }

  /* marking purge sections (take away from input stream and dispose ) */
  c=getch();
  if(c=='/'){ 
    if(c=getch()=='/')
      cmnt=1; // -> full line

    else if(c=='*'){
      cmnt=2; // -> inline
    }

  }
  else if(c=='#')
    cmnt=1;


  /* skip comments, using cmnt and c to keep track */
  while(cmnt){
    c=getch();
    switch(cmnt){
      case 1:
        if(c=='\n')
          cmnt=0; // full line purge done
      break;
      case 2:
        if( c=='*' && (c=getch()) =='/')
          cmnt=0; // inline purge done
      break;
      default:break;
    }  
  }

  /* actual reading */ 
  for( ; --lim>0; w++){
    *w=getch();

    if(*w=='_' || *w=='\'' || *w=='"') // nothing to see here, move along!
      continue;
    
    /* underscore must survive (size_t for example) */
    if( !isalnum(*w) ){
      ungetch(*w);
      break;
    }

  }
  
  *w='\0';
  return word[0];
}

