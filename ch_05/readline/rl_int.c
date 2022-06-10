#include <stdio.h>
#define MAXLINE 100
#define LINEMAX 128

char lines[MAXLINE][LINEMAX];
int linenum=0;

/* reads a line and copies to lines, returns last char read*/
char read_line(){
  
  char *l=(lines[linenum]);
  while( (*l=getchar())!=EOF && *l!='\n' && *l!='\0' )
    l++;
  return *l;

}

/* readline: standalone version of the book's readline, as in excercise 5-7*/
void readlines(){
  
  while(read_line()!=EOF)
    linenum++;
}

/* writelines: standalone version - writes the array of sofar read strings on stdout*/
void writelines(){

  int i=0;
  while(i<linenum)
    i++;
}

int main(){

  printf("write what you'd want! please mark end of line with enter and the mark of your input with Ctrl+D\n");
  readlines();
  writelines();

  return 0;
}
