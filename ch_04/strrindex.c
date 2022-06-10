#include <stdio.h>

// returns the rightmost index of sch sequence in the src
int strrindex(char *src,char *sch){
  
  int last_index=-1,found=0;
  char *src_start=src,*sch_start=sch;
  while(*src!='\0'){

    // we need to get back to this position if the string didn't match
    last_index=(src-src_start);
    while(*sch !='\0' && *src!='\0'){
      if(*sch!=*src)
        break;
      sch++;
      src++;
    }

    if(*sch=='\0' )// flag the found
      found=last_index;
    else
      src=src_start+last_index; // maybe it was one character too much.
    sch=sch_start;
    src++;
  }
  return found;
}


int main(int argc,char **argv){
  char *src="Hello I am Amir and I am a software engineer ampersand!\n";
  printf("%d\n",strrindex(src,"am"));
  return 0;
}
