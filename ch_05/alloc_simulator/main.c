#include "alloc.h"

void psoa(void);
char *alloc(int n);
char *afree(void);

void scp(char dest[],char *src);
void print_diff(const char *s,const char *s1);

int main(int argc,char **argv){

  char *s1,*s2,*s3,*s4;
  
  // not tested yet : 
  // afree() while empty!
  // alloc while fullity full full

  // Imtahanat!
  // char ss[2]=alloc(2); -no :'(
  s1=alloc(10);
  scp(s1,"holy!");
  s2=alloc(5);
  scp(s2,"guzak");
  s3=alloc(5);
  scp(s3,"ahhhh");
  printf("s1 is:'%s'\ns2 is :'%s'\ns3 is:'%s'\n",s1,s2,s3);

  if(afree()==s3)
    printf("freed correctly.\n");

  return 0;
}
