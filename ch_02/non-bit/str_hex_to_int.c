#include <stdio.h>
#include "../../lib/str_work.c"

// note that the argument to the console should be in the
// same format as in ansi-c hex string (beginning with
// "0x" or "0X")
int main(int argc,char **argv){

	char *hex_str=NULL;
	if(argc>0 && argv[1]!=NULL)
		hex_str=argv[1] 
	else
		hex_str="0x98f";
	printf("%s -> %d\n",hex_str,hexstr_to_int(hex_str));

	return 0;
}

