// #include "./getch.c"
#include  "./ungets.c"

int main(){
  
  // ungetching : works fine!
  ungetsr("Howdy mate.");

  // now printing
  char c=' ';
  while(c=getch())
    printf("%c",c);
  printf("\n");

  return 0;
}
