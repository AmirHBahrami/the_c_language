#include <stdio.h>
#define MAX_LINE_CHARS 256
static char line[MAX_LINE_CHARS];
static char *lp=&line[0];
static int len=0;

/*empties the line*/
static void clear_line(void){

  lp--;
  while(lp!=&line[0]){ // TODO there's no todo, it was only to get attention : this line IS KEY!
    *lp='\0';
    --lp;
  }
  len=0;

}

/*pushes one character into the line,returns if any error occurred*/
static int push(char c){
  if(len>=MAX_LINE_CHARS)
    return 1;
  *lp=c;
  lp++;
  len++;
  return 0;
}

static void print(){
  char *shit=&line[0];
  while(*shit!='\0'){
    printf("%c",*shit);
    shit++;
  }
}

/*checks if a string contains another string*/
static int contains(const char *src,const char *str){

  int str_c=0;

  // NOTE the next line cannot be a good point to 
  // remember where the str was, since the str
  // is a const,and trying to init it to another
  // pointer causes violation.
  // ALSO the pointer in grep is a const too,
  // so it cannot call contains in that case
  //char *start=str; // the first character
  
  while(*src!='\0'){
    if(*str=='\0') // meaning it has reached the str to the end
      return 1;
    if(*str==*src){
      str++;
      str_c++;
    }
    else {
      str-=str_c;
      str_c=0;
    }
    src++;
  }
  if(str_c!=0)
    return 1;
  return 0;
}

/*prints found string in a text, returns the number of containing lines*/
int grep(const char *src,const char *str){
  
  int lines_found=0;
  while(*src!='\0'){
    push(*src);
    if(*src=='\n'){
      if(contains(line,str)){
        print();
        lines_found++;
      }
      clear_line();
    }
    src++;
  }
}

int main(int argc,char **argv){
  
  /*
  int i=0;
  if(argc>0){
    while(i<argc){
      printf("%s\n",argv[i]);
      i++;
    }
  }*/
  /*
  if(argc<2){
    printf("please provide both a source and a phrase to look for.\n");
    return 1;
  }*/


  grep("oh there once was a hero named Ragnar the red\nWhere he came to old town near old Rorickstead\nRagnar then fucked a girl named olga\nOlga told her father\nHer father killed the swine\nThen Ragnar didn't lived happily ever at fucking all\n","Ragnar"); 
 // grep(argv[1],argv[2]);
}
