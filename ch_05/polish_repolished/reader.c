#ifndef __POLISH_H
  #include "./polish.h"
#endif

#ifndef __READER_C
  #define __READER_C 1
#endif

char getch();
void ungetch(char c);

void putint(int i);

/* ctype: returns a character's type based on MATH_SIGNS headers */
int ctype(char c){

  if(c>='0' && c<='9')
    return IS_NUM;

  else if (c==' ' || c=='\n' || c=='\t')
    return IS_SPC;

  // bug * would mean all in the console!
  else if (c=='+' || c=='/' || c=='x' || c=='*' || c=='-' || c=='%')
    return IS_SGN;
  
  else 
    return IS_UDF;
}

/* procstr: processes args for calculations from a string */
void procstr(char **args){ // array of strings (supposedly argv)

  char sign;
  int num,num_changed;
  
  // bug * would mean all in the console!
  // traverse strings
  while(*args){

    // reset state
    sign='\0';
    num=0,num_changed=0;

    // one string
    while((**args)!='\0'){

      // one character of that string
      switch(ctype((*args)[0])){
        case IS_SGN:
          if(sign!='\0') // ignore more than one signs
            continue;
          sign=(*args)[0];
        break;

        case IS_NUM:
          num= ( num*10 + ((*args)[0]-'0'));
          num_changed=1;
        break;
        
        default: // skip useless chars
        break;
      }
      
      ++(*args); // to the next char
    }

    // it wasn't a number
    if(num_changed==0){
      if(sign!='\0')
        ungetch(sign); // hope it'll work!
    }
    else{
      if(sign=='-')
        putint(-1*num);
      else  // includes % and * and the rest, so test it!
        putint(num);
    }
    
    args++;
  }

}

#ifdef INTERACTIVE
/* ungets: reads an entire string off the input */
void ungets(char *str){

  printf("write the euqation in reverse polish notaion and put a spcae at the end, then hit ENTER\n");

  // BUG:if there's no space at the end of a string, the last char isn't read
  // BUG:there's an additional 0 read at the end, though it might be a bug of
  // only outputting them in a debug function, must test with real numbers 
  // to see for sure.

  char c=' ',cb='\0'; // cbefore
  int num=0;
  char sign='\0'; // 0 means no sign detected
  while((c=getchar())!=EOF /*&& c!='\0'*/ && c!='\n' ){

    switch(ctype(c)){

      case IS_SPC:

        if(ctype(cb)==IS_NUM){ // a num is read sofar 

          if(sign=='-')
            putint(-1*num);
          else if(sign=='+' || sign=='\0')
            putint(num); // + or nothing
 
          // reset variables
          num=0;
          sign='\0';
        }
        else if(ctype(cb)==IS_SGN){
          ungetch(cb);
          sign='\0'; // reset the sign
        }

      break;

      case IS_NUM:
        num = num*10+ (c-'0'); // update num
      break;
      
      case IS_SGN:
        sign=c;
      break;
      
      case IS_UDF:
      default:
        printf("skipping '%c'...\n",c);
        continue; // do not remember what it was
      break;
    }
    cb=c;
  }

}
#endif

