/**
 *  The process is : 
 *  
 *  zero-mask 'y'
 *  shift 'y' , 'p' bits to right (might need to be p+1)
 *  negate 'y', so that it can be later &'ed with x, and produce a half-perfect number
 *  
 *  in that state, we then need to realize what number x(p) -> x(p-n) was so that we can
 *  filter it now. therefore we define z.
 *
 *  z:=x>>n. // bring the target part of x to it's rightmost (and save in z).
 *  z:= zero-masked. 
 *  z:=z<<n. // now bring back the right position, so now zed is : 00.. ~{x(p)->x(p-n)} ..00 
 *  
 *  the target part is now negated and brought back to it's original place.
 *  now if we mask x & y, then mask it with the negated part, and save it back in x, we'll have
 *  our new x with the set bits to our wish.
 * */
#include <stdio.h>
#include "./itob.c"

char bin_rep[]="0000000000000000";

void itob(int i,int b,char str[]);
void print_b(int i,char name);
int setbits(int *x,int p,int n, int y);

int main(){
  
  int xprev=42,x=42, p=7, n=4, y=9;
  //setbits(&x,p,n,y);
  //printf("x:%d p:%d n:%d y:%d = %d\n",xprev,p,n,y,x);
  print_b(~0,'n');
  return 0;
}

void print_b(int i,char name){
  itob(i,2,bin_rep);
  printf("%c:%d , %s\n",name,i,bin_rep);
}

int setbits(int *x,int p,int n,int y){
  
  print_b(*x,'x');

  y= y&(~(~0<<n));
    print_b(y,'y');
  y= y<<(p-n);
    print_b(y,'y');
  y= y^(~(~0));
    print_b(y,'y');
  
  int z= (*x)>>(p+1-n);
    print_b(z,'z');
  z= z&(~(~0<<n));
      print_b(z,'z');
  z= z<<n;
    print_b(z,'z');
  z= z^(~0);
    print_b(z,'z');

  y= y&(*x);                    print_b(y,'y');
  *x= y&z;                      print_b(*x,'x');
}
