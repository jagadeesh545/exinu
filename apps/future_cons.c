#include <prodcons.h>

uint future_cons(future *fut) {
  //kprintf("tid = %d\n",gettid());
  int i, status;
  status = future_get(fut, &i);
  if (status == SYSERR) {
    printf("future_get failed\n");
    return -1;
  }
  kprintf("consumed %d\n", i);
<<<<<<< HEAD

=======
>>>>>>> 09fc7425b8f941de83db609c5a7ebc2ab3166d50
  if(fut->flag == FUTURE_EXCLUSIVE)
    if(future_free(fut)==SYSERR)
      printf("future_free failed\n");
  return OK;
}

