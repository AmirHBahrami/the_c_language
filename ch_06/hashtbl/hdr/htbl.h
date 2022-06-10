#ifndef __HTBL_H
  #define __HTBL_H 1
#endif

#ifndef __HASH_H
  // TOD0 make this a thing: #include "$SELF_C_DIR/hdr/Hash.h"
  #include "./Hash.h"
#endif

/* hash: hashes a string into an int */
unsigned int hash(char *str);

/* install: puts a key value pair in hash table */
void install(char *n, Hashval hv);

/* locate: gets a hashed element or null */
Hash *locate(char *n);

/* undef: removes a Hash element which matches the hashed n */
void undef(char *n);
