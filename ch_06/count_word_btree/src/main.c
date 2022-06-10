#ifndef __STRBUFF_H
  #include "../hdr/strbuff.h"
#endif

#ifndef __WORD_BUFF_H
  #include "../hdr/word_buff.h"
#endif

#ifndef __STDIO_H
  #include <stdio.h>
#endif

#ifndef __STRING_H
  #include <string.h>
#endif

#ifndef __STDLIB_H
  #include <stdlib.h>
#endif

#ifdef __DEBUG
  void printstr();
#endif

#ifdef __C_KW
/* K & R's c-keyword filtering done differently by me! */
static  char *kw[]={
    "for",
    "if",
    "do",
    "while",
    "char",
    "int",
    "sizeof",
    "struct",
    "void",
    "size_t",
    "FILE"
};
#endif

/* printh: prints help for users */
void printh(void);

int main( int argc, char **argv){
  
  #ifdef __C_KW
    rall_f(' ',kw);

  #else

	  char  sep='\n';
	  char  *sim=NULL;
	  int   nsim=0;
	  
	  /* command line arg parsing */
	  while(*argv){
	
	    if(**argv=='-'){
	      ++(*argv);
	
	      if( **argv=='n' ){
	        ++argv;
	        nsim=atoi(*argv);
	      }
	
	      else if(strcmp(*argv,"sp")==0){
	        ++argv;
	        sep=**argv;
	      }
	      
	      else if(strcmp(*argv,"sim")==0){
	        ++argv;
	        sim=*argv;
	      }
	
	    }
	
	    ++argv;
	  }
	 
	  /* if nsim isn't set it should be the length of sim */
	  if(sim && *sim && nsim==0)
	    for(int i=0;sim[i];i++)
	      ++nsim;

	  if(nsim>0 && sim)
	    rall_s(sep,sim,nsim);
	
	  else 
	    rall(sep);
	
  #endif

  /* retrieve and add them to word buffer */
  char *str;
  while(str=getstr())
    addw(str);
  
  /* printing */
  printw();
}

void printh(){


} 
