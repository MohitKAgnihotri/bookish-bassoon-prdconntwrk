/*
 * Replace the following string of 0s with your student number
 * 000000000
 */
#include "mutex_lockvar.h"

/* mutex.h contains the specification of functions in this file */


/* 
 * DO NOT EDIT the mu_new function.
 */
mutex_t* mu_new(proc_t* proc) {
    return ipc_new(proc, "mutex_lockvar", sizeof(mutex_lockvar_t));
}

/* 
 * TODO: you must implement this function.
 * Hints:
 * - see the section on the lock variable busy waiting "solution" in 
 *     the operating systems material on IPC
 * - remember a mutex_t object is basically an ipc object and the specific
 *      implementation of a mutex (lockvar in this case) in
 *      shared memory is at the addr field of the ipc object (see ipc.h)
 */
void mu_enter(mutex_t* mux) {
    return;
}

/* 
 * DO NOT EDIT the mu_leave function. 
 */
void mu_leave(mutex_t* mux) {
    if (!mux) return;
        
    mutex_lockvar_t* lock = (mutex_lockvar_t*) mux->addr;

    *lock = 0;
}

/* 
 * TODO: you must implement this function.
 * Hint:
 * - look at how the mutex is allocated in mu_new
 */
void mu_delete(mutex_t* mux) {
    return;
}



