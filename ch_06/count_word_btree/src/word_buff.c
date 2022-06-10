#ifndef __WORD_BUFF_H
  #include "../hdr/word_buff.h"
#endif

#ifndef __STDLIB_H
  #include <stdlib.h>
#endif

#ifndef __STRING_H
  #include <string.h>
#endif

#ifndef __STDIO_H
  #include <stdio.h>
#endif


#ifndef __NODE_TDEF
  #define __NODE_TDEF 1
  typedef struct word_node{
    
    char *str;
    int count;
    struct word_node *l;
    struct word_node *r;
  
  } Node;
#endif

static Node *root=NULL;
static Node *p;

static Node *init_node(char *str){
  
  Node *n= (Node *) malloc(sizeof(Node));
  n->str=str;
  n->count=1;
  
  return n;
}

void addw(char *str){
  
  if(!str || !(*str))
    return;

  if(!root){
    root=init_node(str);
    p=root;
    return;
  }
  
    /* firt traverse to destination, and remember the comparison */
  Node *n=root;
  int comp;
  while(n!=NULL){
  
    if( n->str && (comp=strcmp(str,n->str))==0){
      (n->count)+=1;
      return;
    }

    else if(comp<0){
  
      /* put in l */
      if(!(n->l)){
        n->l=init_node(str);
        n->count=1;
        return;
      }

      /* continue traversing l */
      else n=n->l;
    }

    else{

      /* put in r */
      if(!(n->r)){
        n->r= init_node(str);
        n->count=1;
        return;
      }
      
      /* continue traversing r */
      else n=n->r;
    }

  }

}

static void printnr(Node *n){
  
  /* safety measure */
  if(!n) {
    printf("\n");
    return;
  }
  
  printf(" %s <- %s (%d) -> %s \n",n->l?n->l->str:"NULL",n->str,n->count,n->r?n->r->str:"NULL");

  /* preventing a stack frame */
  if(n->l)
    printnr(n->l);
  
  if(n->r)
    printnr(n->r);

}

/* ptrr: print tree recursively */
static void ptrr_inc(Node *n){

  if(!n || !(n->str) || !(*(n->str)) ) // end reached
    return;

  if(n->l)
    ptrr_inc(n->l);
  
  /*if(n->str)*/ //we assume this line isn't needed
  printf("%16s\t(%d)\n",n->str,n->count); /* WARNING: 16%s can be troublesome,it's just a randomly selected number*/

  if(n->r)
    ptrr_inc(n->r);

}

void printw(){

  if( !root || !(root->str)){
    printf("NO_WORDS_READ\n");
    return;
  }
  printf("\n\troot:'%s'\n\n",root->str);
  ptrr_inc(root);
  printf("\n");
}
