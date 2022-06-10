#include <limits.h>
#include <stdio.h>

int main(int argc,char **argv){

  /*
   * this program prints the value range of different data-types.
   * no functions defined : not redundant, heavy or reusable.
   * */
  
  // system's word size:
  printf("word-size:%d\n\n",__WORDSIZE);

  // character
  printf("signed char value range:[%d , %d]\n",SCHAR_MIN,SCHAR_MAX);
  printf("unsigned char max: %d\n\n",UCHAR_MAX);
  
  // short
  printf("signed short value range: [%d , %d]\n",SHRT_MIN,SHRT_MAX);
  printf("unsigned short max: %u\n\n",USHRT_MAX);
  
  // int
  printf("signed int value range:[%d , %d]\n",INT_MIN,INT_MAX);
  printf("unsigned int max: %u\n\n",UINT_MAX);
  
  // long
  printf("signed long value range: [%ld , %ld]\n",LONG_MIN,LONG_MAX);
  printf("unsigned long max: %lu\n\n",ULONG_MAX);
  
}

