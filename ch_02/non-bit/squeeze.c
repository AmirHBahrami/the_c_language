#include <stdio.h>
#include "../../lib/str_work.c"

// char *squeeze (const char*,const char*);
/**
 *  three strings could be given to the console. The third
 *  argumnet will then be used to determine what should happen
 *  to those two strings.
 *  if 0 is given, any(first,second)
 *  else squeeze(first,second);
 * */
int main(int argc,char **argv){

  char *resource=NULL;
  char *resource_minus=NULL;
  int choice=0;
  if( argc>=4){
    resource=argv[1];
    resource_minus=argv[2];
    choice=str_to_int(argv[3]);
  }

  else {
    resource="I\'m a cunt!";
    resource_minus="shate";
  }

  // "any" function
  if(choice==0)
    printf("%s in %s ->  %d\n",
        resource,
        resource_minus,
        any(resource,resource_minus)
     );

  // "squeeze" function
  else
    printf("%s - %s = %s\n",
      resource,
      resource_minus,
      squeeze(resource,resource_minus)
    );


  //printf("%d\n",str_to_int("134"));
  return 0;
}
