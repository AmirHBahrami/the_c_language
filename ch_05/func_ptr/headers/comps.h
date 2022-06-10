#ifndef __COMPS_H
  #define __COMPS_H 1
#endif 

/* strcomp: lexicographic comparison of strings */
int strcomp(char *s,char *s1);

/* stcompcn: stcomp case-neutral*/
int strcompcn(char *s,char *s1);

/* intcomp: compare two ints (duh) */
int intcomp(int a,int b);

/* floatcomp: calculates akkerman in less than a sec! */
int floatcomp(float a,float b);
