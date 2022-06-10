#ifndef __STDIO_H
  #include <stdio.h>
#endif

/* detab: turns \t into n number of whitespaces (prints) */
void detab(char *s,int n){
  /* s should be an initialised char array not some string literal*/

  while(*s){
    if(*s=='\t')
      for(int i=0;i<n;i++)
        printf(" ");
    else 
      printf("%c",*s);
    ++s;
  }
  printf("\n");
}

/* entab: replaces each n whitespaces with \t (prints) */
void entab(char *s,int n){
  /* s should be an initialised char array not some string literal*/

  int i;
  while(*s){
    i=0;

    /* see how many whitespaces are ahead */
    while( *s && *s==' ' ){ 
      ++s;
      ++i;
    }

    /* go back if n whitespaces are not reached */
    if(i<=n)
      s-=i;
    else 
      printf("[\t]");

    printf("%c",*s);
    ++s;
  }
  printf("\n");
}

/* atovar: variable n is extracted from *s */
void atovar(char *s,int *n){

  /* expected input: -22 or +10 , n will be overwritten */
  *n=0;

  /* skip unwanted chars */
  while(*s>'9' || *s<'0')
    ++s;
  
  while(*s && *s<='9' && *s>='0'){
    *n= (10* (*n)) + (*s-'0');
    ++s;
  }
}

int main(int argc,char **argv){

  #ifdef DEBUG

    int n=6;
    char et[64]=" hello       there asswhipe kalleh! ";
    char dt[64]="\tglory\tglory\thallelujah\t. ";
    entab(et,n);
    detab(dt,n);

  #else
	  
    // TODO program is not working, find a way to pass \t from the console!
    // TODO make -o 'd' into -d

	  /* skip program's name */
	  argv++;

    if(!(*argv)){
      printf("no arguments given, use '-h' flag\n");
      return 1;
    }
	
	  int m=-1,n=4,op='e';
	  char *sentence; // make sure this dude get's called out
	
	  while(*argv){

      // printf("reading \"%s\"\n",*argv);
	
	    switch((*argv)[0]){

	
	      case '-':

          // printf("at '%c' -> '%c'\n",(*argv)[0],(*argv)[1]);

	        /* reading extra and necessary options*/
	        switch((*argv)[1]){

            case 'h':
	            printf("tabber - usage : tbr [-h,-o,\\+{\\d*},-{\\d*}] [-s] '{\\w*}' \n");
              printf("**use 'string' or \"string\" to pass the input string\n");
              printf("-h\tprints out this help\n");
              printf("-o\toperation to do. possible options are 'd' (detab) and 'e' (entab)\n");
              printf("+{\\d*}\tflag '+' is used to skip {\\d} first character of input string\n");
              printf("-{\\d*}\tflag '-' is used to set the number of tabs <-> space equivalence ( e.g. 2 means each tab is 2 spaces )\n");
              printf("-s\tif present the next value will be read as input string\n");
              return 0;
            break;

	          case 's':
	            sentence= *(++argv); // the next is the sentence
              // printf("-s : \"%s\"\n",sentence);
	          break;
	
	          case 'o':

              // printf("next char: '%c'\n",(*(++argv))[0]);

	            /* the next string */
	            if( (*(++argv))[0] == 'd' )
	              op='d';
	            else if( (*argv)[0] == 'e')
	              op='e';
	            else {
	              printf("option '%c' not recognised. get some -h , buddy!\n",(*argv)[0]);
	              return 1;
              }
               
              // printf("-o : %c\n",op);
	          break;
	
	          default: // no extra option given	
	            atovar(*argv,&m);
              // printf("-m : %d\n",m);
	          break;
	        }
	      break;
	
	      case '+':

          atovar(*argv,&n);
          // printf("-n : %d\n",n);
	      break;
	
	      default:
          // printf("'%s' is the default case.\n",*argv);
        break;

	    }
	    
	    /* if sentence is set, this is still relevant */
      ++argv;
	
	  }
	  
	  /* in case -s flag isn't used */
	  if(!(*sentence) &&  !(sentence=*(--argv))){
      printf("please seek -h !\n");
      return 1;
    }
	
	  /* move sentence pointer */
	  while(m>0 && *sentence){
	    ++sentence;
	    --m;
	  }
	
	  if(op=='e')
	    entab(sentence,n);
	
	  else 
	    detab(sentence,n);
	
  #endif

  return 0;
}
