#ifndef __HASH_H
  #include "../hdr/Hash.h"
#endif

#ifndef __HASHTBL_H
  #include "../hdr/htbl.h"
#endif 

#ifndef __STRBUF_H
  #include "../hdr/strbuf.h"
#endif

#ifndef __STDIO_H
  #include <stdio.h>
#endif

#ifndef __STRING_H
  #include <string.h>
#endif

/* a keys array easier showcase that the words are read already */
char *keys[64];

int main(int argc,char **argv){
   
  rall();

  int i=0;
  char *s;
  char *s1;
  while((s=gets())!=NULL){
    if(strcmp(s,"#define")==0){

      /* get the key and the value, and install them if not null */
      s=gets();
      s1=gets();
      if(s1 && s){
        keys[i]=s;
        install(s,s1);
        ++i;
      }
    }
  }
  
  char **rdr=keys;
  while(*rdr){
    printf("%31s : %s\n",*rdr,locate(*rdr)->val);
    ++rdr;
  }
  
  /* for manual testing */
  /*
  install("jckrdr","wank");
  install("jackrdr","holy");
  
  Hash *h=locate("jackrdr");
  printf("%s:%s\n",h->key,h->val);
  
  install("Nureddin","wack 'em all");
  
  h=locate("Nureddin");
  undef("Nureddin");
  printf("Nureddin:%s\n",h==NULL?h->val:" VALUE_NOT_FOUND");
  */
  
  return 0;
}
