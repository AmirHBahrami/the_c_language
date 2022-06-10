#include <stdio.h>

float atof(const char*);


int main(void){
  
  char shit[]="18.4";
  printf("%f\n",atof(shit));
  return 0;
}

// turns a string into a float
float atof(const char *str){
  
  float f=0.0f;
  int deca=1; // how many integers it has

  // how many integers
  for(int ints=0; str[ints]!='.' && str[ints]!='\0';ints++){
    
    #ifdef DEBUG
    printf("\tdeca:%d,str[%d]:%c\n",deca,ints,str[ints]);
    #endif

    deca*=10;
  }

  #ifdef DEBUG
  printf("deca:%d,f:%8.4f\n",deca,f);
  #endif
  
  int i=0; // sothat the next loop start where this one ends
  for(char ch=' '; (ch=str[i])!='.' && ch!='\0' && deca>1 ; i++){ // adding integers to f

    f+= (ch-'0') * deca;
    deca/=10; // move one digit lower

    #ifdef DEBUG
    printf("\tf:%8.4f,deca:%d,ch:%c\n",f,deca,ch);
    #endif
  }

  i++; // moving the iterator to where the '.' starts

  #ifdef DEBUG
  printf("point reached.\n");
  #endif

  // fractions
  float fract=1.0f;
  for(char ch=' '; (ch=str[i])!='\0';i++){
    
    fract*=0.1f;

    #ifdef DEBUG
    printf("\tf:%8.2f,deca:%d,ch:%c,fract:%4.2f\n",f,deca,ch,fract);
    #endif

    if((ch -='0')==0){

      #ifdef DEBUG
      printf("\t%d , skipping...\n\n",ch);
      #endif

      continue;
    }
    f +=ch*fract;

    #ifdef DEBUG
    printf("\tf:%8.2f,deca:%d,ch:%d,fract:%8.4f,ch*fract=%8.4f\n\n",f,deca,ch,fract,(ch*fract));
    #endif

  }

  #ifdef DEBUG
  printf("final, before returning:%f\n",f);
  #endif

  return f;
}
