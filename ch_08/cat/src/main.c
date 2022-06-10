#ifndef __CAT_H
  #include "../hdr/cat.h"
#endif

#ifndef __UNISTD_H
  #include <unistd.h>
#endif

#ifndef BUFSIZ
  #define BUFSIZ 1024
#endif

int main(int argc, char **argv){
  
  if(!argv[1] || *argv[1]=='\0'){
    write(2,"usage : cat <filepath>\n",BUFSIZ);
    return 1;
  }
  cat(argv[1]);
  return 0;
}
