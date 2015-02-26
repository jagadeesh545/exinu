#include <kernel.h>
#include <future.h>

syscall future_set(future *f, int value) {
  if(f->state == FUTURE_EMPTY || f->state == FUTURE_WAITING){
    f->value = value;
    f->state = FUTURE_VALID;
    //kprintf("future produced\n");
    future_signal(f);
    return OK;
  }
  else
  {
    return SYSERR;
  }
}
