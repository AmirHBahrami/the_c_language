#ifndef __CAT_H
  #include "../hdr/cat.h"
#endif

#ifndef __UNISTD_H
  #include <unistd.h>
#endif

#ifndef __FCNTL_H
  #include <fcntl.h>
#endif

#ifndef BUFSIZ
  #define BUFSIZ 1024 
#endif

#ifdef DEBUG
  #ifndef __STIO_H
    #include <stdio.h>
  #endif
#endif

void cat(char *path){
   
  /* NOTE: if you write(,,BUFSIZ), it will print gibberish after
   * the buffer is empty, so write(,,br)*/
  char buf[BUFSIZ];
  int br=0; /* bytes read*/

  /* open file and print error if any happened */  
  int fd=open(path,O_RDONLY,S_IRUSR);
  if(fd==-1){
    write(2,"cat: couldn't open or access the file \n",BUFSIZ);
    write(2,path,BUFSIZ);
    return;
  }
  
  while((br=read(fd,buf,BUFSIZ))> 0){
    #ifdef DEBUG
      printf("\n(%d bytes read)\n",br);
    #endif
    write(1,buf,br);
  }
  write(1,"\n",1); /* zeilenumbruch */

  close(fd);
}
