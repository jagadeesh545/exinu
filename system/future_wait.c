/**
 * @file future_wait.c
 *
 */

#include <thread.h>
#include <future.h>

/**
 * @ingroup futures
 *
 * Wait on a future.
 *
 * If the semaphore's count is positive, it will be decremented and this
 * function will return immediately.  Otherwise, the currently running thread
 * will be put to sleep until the semaphore is signaled with signal() or
 * signaln(), or freed with semfree().
 *
 * @param sem
 *      Semaphore to wait on.
 *
 * @return
 *      ::OK on success; ::SYSERR on failure.  This function can only fail if @p
 *      sem did not specify a valid semaphore.
 */
syscall future_wait(future *fut)
{
    //register struct sement *semptr;
    register struct thrent *thrptr;
    irqmask im;

    im = disable();
    /*if (isbadsem(sem))
    {
        restore(im);
        return SYSERR;
    }*/
    thrptr = &thrtab[thrcurrent];
    //semptr = &semtab[sem];

    if (fut->state == FUTURE_EMPTY || fut->state == FUTURE_WAITING)
    {
        thrptr->state = THRWAIT;
        if(fut->tid=-1) fut->tid = thrcurrent;
        resched();
    }
    restore(im);
    return OK;
}
