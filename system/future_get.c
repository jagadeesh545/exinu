#include <kernel.h>
#include <future.h>
#include <semaphore.h>

syscall future_get(future *f, int *value) {

  /*semaphore sem;
  sem = semcreate(1);*/
  
  if(f->state == FUTURE_EMPTY){
    //f->tid = gettid();
    //kprintf("future empty\n");
    f->state = FUTURE_WAITING;
    future_wait(f);
    *value = f->value;
    f->state = FUTURE_EMPTY;
    //kprintf("future consumed\n");
    return OK;
  }

  if(f->state == FUTURE_WAITING){
    //kprintf("future waiting\n");
    return SYSERR;
  }

  if(f->state == FUTURE_VALID){
    *value = f->value;
    f->state = FUTURE_EMPTY;
    //kprintf("future valid\n");
    return OK;
  }
}
