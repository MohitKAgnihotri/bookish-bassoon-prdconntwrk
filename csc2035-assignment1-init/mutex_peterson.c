/*
 * Replace the following string of 0s with your student number
 * 000000000
 */
#include "mutex_peterson.h"

/* mutex.h contains the specification of functions in this file */

/* 
 * TODO: you must implement this function
 * Hints:
 * - see mutex_lockvar.c for how mu_new is implemented there but remember
 *      that the underlying mutex type allocated in shared memory and 
 *      encapsulated by the IPC type will be different
 * - the shared object label should be mutex_peterson
 * - also see: mutex_peterson.h, mutex_lockvar.c and ipc.h
 */
mutex_t* mu_new(proc_t* proc) {
    return NULL;
}

/* 
 * TODO: you must implement this function.
 * Hints:
 * - see the section on the Peterson's busy waiting solution in 
 *     the operating systems material on IPC
 * - process ids must be normalised to either a 0 or 1 for indexing 
 *      into the interested array (there is an arithmetic operator to do this)
 * - remember a mutex_t object is basically an ipc object and the specific
 *      implementation of a mutex (Peterson's in this case) in
 *      shared memory is at the addr field (see ipc.h)
 * - also see: mutex_lockvar.c
 */
void mu_enter(mutex_t* mux) {
    return;
}

/* 
 * TODO: you must implement this function.
 * Hints: see hints for mu_enter
 */
void mu_leave(mutex_t* mux) {
    return;
}

/* 
 * TODO: you must implement this function.
 * Hint:
 * - deallocate what you allocate in mu_new
 */
void mu_delete(mutex_t* mux) {
   return;
}
