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

typedef struct word_node{
  
  char *str;
  int count;
  struct word_node *l;
  struct word_node *r;

} Node;

static Node *root=NULL;
static Node *p;

static Node *init_node(char *str){
  
  Node *n= (Node *) malloc(sizeof(Node));
  n->str=str;
  n->count=1;
  
  return n;
}

void addw(char *str){
  
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
  
  printf("{ '%s' (%d) ",n->str,n->count);
  printf("| l:'%s' | r:'%s' }\n\n",n->l?n->l->str:"NULL",n->r?n->r->str:"NULL");

  /* preventing a stack frame */
  if(n->l){
    // printf("l:{ '%s' | %d }\n\n",n->l->str,n->l->count);
    printnr(n->l);
  }
  
  if(n->r){
    // printf("r:{ '%s' | %d }\n",n->r->str,n->r->count);
    printnr(n->r);
  }

}

void printw(){

  printnr(root);
}
