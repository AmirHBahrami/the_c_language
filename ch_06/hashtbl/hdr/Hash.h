#ifndef __HASH_H
  #define __HASH_H 1
#endif

/* i added this just for more practice and fun,you may compile   
 * so this is so for only this program, but it's reusable in case
 * youwanted*/
typedef char *Hashval;

typedef struct hash_struct{

  char *key;
  Hashval val;
  struct hash_struct *next;

} Hash;

/* (optional) hshcmp: compares two Hash structs */
// int hshcmp(Hash *h1,Hash *h2);
