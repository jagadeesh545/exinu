#include <prodcons.h>

uint future_prod(future *fut) {
  //kprintf("tid = %d\n",gettid());
  int i, j=0;
  j = (int)fut;
  for (i=0; i<=1000; i++) {
    j += i;
  }
  if(future_set(fut, j)==OK){
    //printf("future set to %d\n",fut->value);
    return OK;
  }
  else {
    printf("future set failed\n");
    return SYSERR;
  }
}

