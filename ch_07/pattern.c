#include <stdio.h>
#include <string.h>

#define FILE_CAP 16
#define LINE_CAP 64

static FILE *f[FILE_CAP];


#ifdef PATTERN
  #define NAME "PAT"

  /* K&R 7-7 */
  /* findln: finds the line numbers of a phrase happening in a file */
  void findlns(char *s,FILE *f,char *fname);
#endif

#ifdef CAAT
  #define NAME "CAAT"
  #define PAGE_LINE_LIMIT 3

  /* K&R 7-8 */
  /* prpg: prints a file in a paged manner */
  void prpg(FILE *f,char *fname,int pll);

#endif



int main(int argc,char **argv){
  
  #ifdef PATTERN
    argc=2; /* the first argument is the phrase to look for */
  #elif CAAT == 1
    argc=1;
  #endif

  int i=0;
  while(argv[argc]){
    f[i]=fopen(argv[argc],"r");
    if(f[i]==NULL || ferror(f[i])){
      fclose(f[i]);
      --i;
    }
    ++i;
    ++argc;
  }
  
  /* finding the lines and closing the files */
  i=0;

  #ifdef PATTERN
    argc=2;
  #elif CAAT == 1
    argc=1;
  #endif

  printf("compiled with '%s'\n",NAME);
  while(f[i]){

    #ifdef PATTERN
      findlns(argv[1],f[i],argv[argc]);
    #elif CAAT == 1
      prpg(f[i],argv[argc],PAGE_LINE_LIMIT);
    #endif

    if(ferror(f[i]))
        fprintf(stderr,"error reading '%s'\n",argv[argc]);
    fclose(f[i]);
    ++i;
    ++argc;
  }

  return 0;
}


#ifdef PATTERN
void findlns(char *s,FILE *f,char *fname){

  char l[LINE_CAP];
  int ln=1;
  while(!ferror(f) && !feof(f) && fgets(l,LINE_CAP,f)){
    if(strstr(l,s))
      printf("%8s\t%4d.%s",fname,ln,l);
    ++ln;
  }

}
#elif CAAT == 1
void prpg(FILE *f,char *fname,int pll){
  
  printf("\n--%s\n",fname);
  char l[LINE_CAP];
  int ln=0,pg=1;
  while(!feof(f) && !ferror(f) && fgets(l,LINE_CAP,f)){
    if(ln==pll){
      ++pg;
      printf("\n--Page %d\n\n",pg);
      ln=0;
    }
    printf("%s",l);
    ++ln;
  }
  putchar('\n'); 
}
#endif
