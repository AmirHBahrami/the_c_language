#ifndef __POLISH_H
  #include "./polish.h"
#endif

void ungetch(char c);
char getch();

void putint(int i);
int getint();

#ifdef DEBUG
  void printints();
  int peekint();
#endif

#ifdef INTERACTIVE
  void ungets();
#else
  void procstr();
#endif

int calc();

int main(int argc,char *argv[]){

  // TODO add a --help | -h option support
  // TODO add a --verbose | -v option support

  argv++; // the first arg isn't needed.

  #ifdef INTERACTIVE
  while(true){
    ungets();
    printf("= %d\n",calc());
  }
  #else
    procstr(argv);
    printf("peekint():%d\n",peekint());
    printf("= %d\n",calc());
  #endif
  

  #ifdef DEBUG
    char c;
    printf("------------\n");
    while((c=getch())!='\0')
      printf("read:'%c'\n",c);
    printf("\n"); 
    printints();
  #endif
  return 0;
}
