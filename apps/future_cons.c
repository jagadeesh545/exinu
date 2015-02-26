#include <prodcons.h>

uint future_cons(future *fut) {
  int i, status;
  status = future_get(fut, &i);
  if (status == SYSERR) {
    printf("future_get failed\n");
    return -1;
  }
  printf("consumed %d\n", i);
  if(future_free(fut)==SYSERR)
	printf("future_free failed\n");
  return OK;
}

