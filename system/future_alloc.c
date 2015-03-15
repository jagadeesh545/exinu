#include <kernel.h>
#include <future.h>
#include <queue.h>

future* future_alloc(int future_flag)
{
  if(future_flag!=FUTURE_EXCLUSIVE 
	&& future_flag!=FUTURE_SHARED 
	&& future_flag!=FUTURE_QUEUE )
  {
	kprintf("future_alloc: invalid flag\n");
        return NULL;
  }

  future *fut;
  fut = (future *) memget(sizeof(future));

  if (SYSERR == (uint)fut)
 {
    kprintf("future_alloc: insufficient memory\n");
    return NULL;
 }
  else
  {
    fut->value = 0;
    fut->state = FUTURE_EMPTY;
    fut->flag = future_flag;
    fut->tid = -1;
    if(future_flag == FUTURE_SHARED || future_flag == FUTURE_QUEUE)
	fut->get_queue = queinit();
    if(future_flag == FUTURE_QUEUE)
	fut->set_queue = queinit();
    return fut;
  }  
}
