#ifndef __HASH_H
  #include "../hdr/Hash.h"
#endif

#ifndef __HTBL_H
  #include "../hdr/htbl.h"
#endif

#ifndef __STRING_H
  #include <string.h>
#endif

#ifndef __STDLIB_H
  #include <stdlib.h>
#endif

#ifndef __STDIO_H
  #include <stdio.h>
#endif

#ifndef MAX_HASHES

  /* 100 as in c's compiler convention */
  #define MAX_HASHES 101
#endif

#ifndef MAX_STR_LEN 
  #define MAX_STR_LEN 32
#endif

static Hash *htbl[MAX_HASHES];

/* good practice : return unsigned int where index is needed */
unsigned int hash(char *str){   /* reduced str mod MAX_HASHES (see K&R)*/

  unsigned int h=0;
  for(char *s=str; *s; s++)
    h= *s + 31 + h;

  return h % MAX_HASHES;
  
}


void install(char *n,Hashval hv){

  int i=hash(n);
  Hash *h=htbl[i];
  if(!h){
    h = (Hash *)malloc(sizeof(Hash));
    
    /* NOTE: you should use strcpy, bc then when you
     * test in main, if you use string literals, those
     * are allocated in code section, so you won't be 
     * able to release that. but in this case you are.
     * (see the screenshot in project root. */

    /* dealing with key*/
    h->key= (char *)malloc(sizeof(char)*MAX_STR_LEN);
    strcpy(h->key,n);

    /* dealing with val*/
    h->val= (char *)malloc(sizeof(char)*MAX_STR_LEN);
    strcpy(h->val,hv);
    
    /* don't forget this dude! */
    htbl[i]=h;
  }

  else{
    
    /* NOTE: stops at some full Hash with empty next */
    for(;h->next; h=h->next);
    h->next = (Hash *)malloc(sizeof(Hash));

    /* key */
    h->key= (char *)malloc(sizeof(char)*MAX_STR_LEN);
    strcpy(h->next->key,n);

    /* val */
    h->key= (char *)malloc(sizeof(char)*MAX_STR_LEN);
    strcpy(h->next->val,hv);
  }

}


Hash *locate(char *n){
  int i=hash(n);
  Hash *h=htbl[i];
  while( h ){
    if(strcmp(h->key,n)==0)
      break;
    h=h->next;
  }
  return h; /* which can be NULL!*/
}


void undef(char *n){
  
  int i=hash(n);
  if(!htbl[i])
    return; /* nothing removed */

  Hash *h=htbl[i];
  Hash *prev=h;
  while( h ){

    if(strcmp(h->key,n)==0){
      if(h->val)
        free(h->val); /* error: wrong pointer type? */
      free(h);
     if(h->next) /* for a consistent chain */ 
        prev->next=h->next;
      return;
    }

    prev=h;
    h=h->next;
  }
}
