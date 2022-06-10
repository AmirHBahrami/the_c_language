#include <stdio.h>
#define MAXLINE 100
#define LINEMAX 128

char lines[MAXLINE][LINEMAX];
char (*lp)[LINEMAX]=&(lines[0]);

/* readline: standalone version of the book's readline, as in excercise 5-7*/
void readlines(){
  char *l=lp[0]; // current line
  while((*l=getchar())!=EOF){
    
    if(*l=='\n'){
      *l='\0';
      lp=&(lines[(lp-lines)+1]);
      l=*lp; // move the current cursor to next line
    }

    else
      l++;
  }
  
}

/* writelines: standalone version - writes the array of sofar read strings on stdout*/
void writelines(){

  char (*l)[LINEMAX]=&(lines[0]);
  printf("\nyou have entered %ld lines:\n\n",(lp-l));
  while(l!=lp){
    printf("%3ld:\t%s\n",(l-lines+1),*l);
    l++;
  }
  printf("\n");
}

int main(){

  printf("write what you'd want!\nsig end of each line with enter\nsig your input end with Ctrl+D:\n\n");
  readlines();
  writelines();

  return 0;
}
