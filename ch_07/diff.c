#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_CAP 256

void diff(FILE *f,FILE *f1);
static char *f_name,*f1_name;

int main(int argc,char **argv){
  
  ++argv;
  f_name=*argv;
  
  ++argv;
  f1_name=*argv;

  FILE *f,*f1;
  f=fopen(f_name,"r");
  f1=fopen(f1_name,"r");
  

  diff(f,f1);

  fclose(f);
  fclose(f1);

  exit(0);
}

void diff(FILE *f,FILE *f1){
  
  char l[LINE_CAP],l1[LINE_CAP];
  int ln=0;
  while(1){
    
    fgets(l,LINE_CAP,f);
    fgets(l1,LINE_CAP,f1);

    ++ln;

    if(ferror(f)){
      fprintf(stderr,"--error reading '%s'\n",f_name);
      return;
    }

    if(feof(f)){
      fprintf(stderr,"--'%s' has reached it's end .\n",f_name);
      return;
    }

    if(ferror(f1)){
      fprintf(stderr,"--error reading '%s'\n",f1_name);
      return;
    }

    if(feof(f1)){
      fprintf(stderr,"--'%s' has reached it's end.\n",f1_name);
      return;
    }
    
    if(strcmp(l,l1)!=0){
      printf("L%d\n--[%8s] %s",ln,f_name,l);
      printf("--[%8s] %s",f1_name,l1);
      putchar('\n');
    }

  }
  
  putchar('\n');
}
