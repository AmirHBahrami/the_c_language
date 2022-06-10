#ifndef __QSORT_H
  #define __QSORT_H 1
#endif

/* qsort: itreative quick sort (only one iteration 1d) */
void qsort(void **arr,int length,int (*comp)(void *,void *));
