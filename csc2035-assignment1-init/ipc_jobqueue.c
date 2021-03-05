/*
 * Replace the following string of 0s with your student number
 * 000000000
 */
#include "ipc_jobqueue.h"

/* 
 * DO NOT EDIT the ipc_jq_new function.
 */
ipc_jobqueue_t* ipc_jq_new(proc_t* proc) {
    ipc_jobqueue_t* ijq = ipc_new(proc, "ipc_jobqueue", sizeof(jobqueue_t));
    
    if (!ijq) 
        return NULL;
    
    if (proc->is_init)
        jq_init((jobqueue_t*) ijq->addr);
    
    return ijq;
}

/* 
 * TODO: you must implement this function.
 * Hint:
 * - look at how the shared jobqueue_t is accessed in ipc_jq_new and 
 *      passed to jq_init (ipc_jq_new initialises the shared 
 *      jobqueue by passing it to a function defined in jobqueue.h)
 */
size_t ipc_jq_capacity(ipc_jobqueue_t* ijq) {
    return 0;
}

/* 
 * TODO: you must implement this function.
 * Hints:
 * - this is a wrapper for jobqueue function jq_denqueue
 * - and remember you must call do_critical_work after dequeuing the job
 */
job_t ipc_jq_dequeue(ipc_jobqueue_t* ijq) {
    return UNUSED_ENTRY;
}

/* 
 * TODO: you must implement this function.
 * Hint:
 * - see ipc_jq_dequeue hint
 */
void ipc_jq_enqueue(ipc_jobqueue_t* ijq, job_t j) {
    return;
}
    
/* 
 * TODO: you must implement this function.
 * Hint:
 * - see ipc_jq_dequeue hint
 */
bool ipc_jq_is_empty(ipc_jobqueue_t* ijq) {
    return true;
}

/* 
 * TODO: you must implement this function.
 * Hint:
 * - see ipc_jq_dequeue hint
 */
bool ipc_jq_is_full(ipc_jobqueue_t* ijq) {
    return true;
}

/* 
 * TODO: you must implement this function.
 * Hint:
 * - see ipc_jq_dequeue hint
 */
job_t ipc_jq_peekhead(ipc_jobqueue_t* ijq) {
    return UNUSED_ENTRY;
}
    
/* 
 * TODO: you must implement this function.
 * Hint:
 * - see ipc_jq_dequeue hint
 */
job_t ipc_jq_peektail(ipc_jobqueue_t* ijq) {
    return UNUSED_ENTRY;
}

/* 
 * TODO: you must implement this function.
 * Hint:
 * - look at how the ipc_jobqueue is allocated in ipc_jq_new
 */
void ipc_jq_delete(ipc_jobqueue_t* ijq) {
    return;
}
