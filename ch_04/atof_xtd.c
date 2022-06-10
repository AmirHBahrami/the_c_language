#include <stdio.h>

float atof(char *str){ // for the sake of working with pointers, i use pointer iteration

  // two things achieved : 
  // 1. won't be messed with original pointer's first location  
  // 2. faster iteration with pointer
  // down side :
  // 1. the original array is still manipulable
  // if you use const in args, a warning will be printed only!
  char *sp=str;

  float result=0.0f,expo=0.1f;
  int sign=1,sc_not; // , scientific notation
  
  // skip whitespace
  while(*sp!='\0' && *sp==' ')
    sp++;
    
  // dealing with the sign
  if(*sp=='-'){
    sign=-1;
    sp++;
  }
  
  // complete number
  while(*sp !='\0' && '0'<= *sp && *sp<='9'){ // && !='.' obviously!
    result= (result * 10) + (*sp - '0');
    sp++;
  }

  result *= sign; // result is not zero anymore. (though -0 is a thing in c! still it is more comfortable.)

  // if there is any exponential part
  if(*sp=='.') // bullshit potential : if you make str[len-1]='.' it'll get fucked up.
    sp++;
 
  // expo=0.1f;
  while(*sp!='\0' && '0' <= *sp && *sp<='9'){ // && *sp!='e' obviously!
    result =  result + ((*sp -'0')*expo);
    expo/=10;
    sp++;
  }

  // -- up until now the float num is read like this : 33.4456

  // Wissenschaftliche Notation
  if(*sp=='e')
    sp++;

  // e-2 = * 0.01 | e3 == 1000
  sign=1;
  if(*sp=='-'){
    sign=0; // for the use in the loop
    expo=0.1;
  }

  else 
    expo=10;

  sp++;
  
  // reading the scientific notator itself ( 22 or 133 => while!)
  sc_not=0;
  while(*sp!='\0' && '0'<=*sp && *sp<='9'){
    sc_not+= *sp -'0';
    sp++;
  }
  
  // TODO 
  // if(sc_not > some_safe_size)
  //  sc_not = some_safe_size;
  
  // applying the sc_not
  while(sc_not>0){
    if(sign==0)
      expo/=10;
    else 
      expo*=10;
    sc_not--;
  }
  result *= expo;
  return result;
}

int main(int argc, char **argv){
  char *str="   90.99";
  if(argc>1)
    str=argv[1];
  float res=atof(str);
  printf("\t%20.20f\n",res);
  return 0;
}
