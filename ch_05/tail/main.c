#ifndef __TAIL_C
  #include "./tail.h"
#endif

#ifndef _READL_H
  #include "./readl.h"
#endif

char *getl();
int putl(char *l);
void prtl(int n,int line_num);

int readl(char **line);

/* atoint: parses a string into integer */
int atoint(char *str){

  int n=0;
  while(*str && *str>='0' && *str<='9'){
    n=(n*10)+(*str-'0');
    ++str;
  }

  return n;
}

int main(int argc,char *argv[]){
  
  /* parsing arguments */
  ++argv;
  int n=3,l=0;
  while(*argv){
    
    switch(**argv){
      
      case '-':
        switch(*(++(*argv))){
        
          case 'l':
            l=1;
          break;

          default:
            n=atoint(*argv); // the pointer to current thing

            /* gibberish given */
            if(n==0){
              printf("usage: tail -[number of lines]\n");
              return 1;
            }

          break;
        }
      break;
      default: break;
    }
    
    /* NOTE : if you remove the next line, this loop
     * won't terminate but for some reason,
     * the program is entered in input mode!*/
    ++argv;
  }

  /* reading the actual input */
  char *line;
  while(readl(&line))
    putl(line);

  /* printing out */
  prtl(n,l);

 return 0; 
}
