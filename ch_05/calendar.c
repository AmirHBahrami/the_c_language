#include <stdio.h>

static int daytab[2][13]={
  {0,31,28,31,30,31,30,31,31,30,31,30,31},
  {0,31,29,31,30,31,30,31,31,30,31,30,31} // for leap years
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year,int month, int day){
  
  // error-checking task
  if( year<=0 || month<=0 || day<=0 || day > 31 || month >12)
    return -1;
  
  int (*month_ptr)[13],(*start)[13];
  month_ptr = ( year%4==0 && year%100!=0 || year%400==0 ?&daytab[0]:&daytab[1]);
  start=&(*month_ptr);

  // pointer task
  while(month_ptr-start<month){

    // NOTE 1: to access some pointer's raw value you need to follow
    // it's exact declaration.

    // NOTE 2: (*start) won't move, therefore the indexing works,
    // but month_ptr moves so (*leap) won't work.

    day+=(*start)[month_ptr-start];
    month_ptr++;
  }

  return day;
  
}

/* month_day: set month,day from the day of year*/
void month_day(int year,int yearday, int *pmonth, int *pday){

  // error-checking task
  if( year<=0 || yearday<=0 || yearday > 365 ){
    *pmonth=-1;
    *pday=-1;
  }
  
  // the fucking fuck aufgabe etliou5231YREDNMZX 
  int leap, (*month_ptr)[13] , (*start)[13];
  leap = ( year%4==0 && year%100!=0 || year%400==0 ); // either 0 or one, so the index of our month_day arra
  
  // init month variables
  month_ptr=&daytab[0];
  start=&(*month_ptr);
   
  // I think learning c is both a good use of time and a big time waste.
  // if it were java, I would have done much more in the same amount of time.
  *pday=0;
  *pmonth=0;
  while(yearday>29 && (month_ptr-start)>=0){
    yearday-=(*start) [month_ptr-start];
    month_ptr++;
    (*pmonth)++;
  }
  
  // the rest of it remaining.
  *pday=yearday-1;

}

int main(){
  
  // int (*fuck)[13]=&(daytab[0]);
  // printf("1995-07-06 was the %dth day of the year.\n",day_of_year(1995,7,6));
  int day=-2,month=-2;
  month_day(1995,188,&month,&day);
  printf("188th day of the year 1995 was the %dth day of %dth month of the year.\n",day,month);
  return 0;
}
