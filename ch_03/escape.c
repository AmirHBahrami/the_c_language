#include <stdio.h>
#include <stdlib.h>

int str_len(const char *);
int count_escape(const char *);
char *escape(const char *);

int main(){
  
  //char *shit="\tfuck this shit I\'m out...\n";
  char *shit="\t\n fuck off.";
  printf("%s\n",escape(shit));
  return 0;
}

int str_len(const char *str){

  int i=0;
  while(str[i])
    ++i;
  return i;
}

int count_escape(const char *str){
  
  int e=0,i=0;
  while(str[i]){
    if(str[i]=='\t' || str[i]== '\n' || str[i]==' ')
      e++;
    i++;
  }

  return e;
 
}

char *escape(const char *str){
  
  int len=str_len(str)+count_escape(str);
  printf("len:%d\n",len);
  char *temp=(char *)malloc(sizeof(char)*len);

  //printf("%d\n",str_len(temp));
  
  int i=0;
  int temp_c=0;
  while(str[i]){
    
    char c=str[i];
    if( c =='\t' || c=='\n' ){
      temp[temp_c]='\\';
      temp_c++;

    }
    switch(c){
      case '\t': temp[temp_c]='t'; break;
      case '\n': temp[temp_c]='n'; break;
      case ' ':temp[temp_c]='_';break;
      default:
               temp[temp_c]=str[i]; 
               break;
    }
    temp_c++;
    //printf("%c,%s,%d\n",str[i],temp,str_len(temp));
    i++;
  }
  
  //printf("temp:%s\n",temp);
  return temp;
}
