/*
 * Replace the following string of 0s with your student number
 * 000000000
 */
#include <stdlib.h>
#include <stdbool.h>
#include "jobqueue.h"

const job_t UNUSED_ENTRY = { -1, -1 };

/* 
 * DO NOT EDIT the jq_init function.
 */
void jq_init(jobqueue_t* jq) {
    jq->head = 0;
    jq->tail = 0;
    jq->buf_size = JOBQ_BUF_SIZE;

    for (int i = 0; i < jq->buf_size; i++)
        jq->jobs[i] = UNUSED_ENTRY;
}

/* 
 * TODO: you must implement this function to allocate a job queue and 
 * initialise it.
 */
jobqueue_t* jq_new() {
    jobqueue_t* newjq = (jobqueue_t*) malloc(sizeof(jobqueue_t));
    if (newjq)
    {
        jq_init(newjq);
    }
    return newjq;
}

/* 
 * TODO: you must implement this function.
 */
size_t jq_capacity(jobqueue_t* jq) {
    return jq->buf_size - 1;
}

/* 
 * TODO: you must implement this function.
 * Hints
 * - if the queue is empty, just return an appropriate value for the job
 * - if the queue is not empty, return the value of the entry at the
 *      appropriate position and update queue state before returning.
 *      Remember to mark the queue slot at the position as unused 
 */
job_t jq_dequeue(jobqueue_t* jq) {
    job_t dequeued_job = {0,0};
    if (jq_is_empty(jq))
        return UNUSED_ENTRY;
    else
    {
        dequeued_job = jq->jobs[jq->head];
        jq->jobs[jq->head] = UNUSED_ENTRY;
        jq->head = (jq->head + 1) % jq->buf_size;
        return dequeued_job;
    }
}

/* 
 * DO NOT EDIT the jq_enqueue function.
 */
void jq_enqueue(jobqueue_t* jq, job_t j) {  
    if (jq_is_full(jq))
        return;
        
    jq->jobs[jq->tail] = j;

    jq->tail = (jq->tail + 1) % jq->buf_size;
}
   
/* 
 * DO NOT EDIT the jq_is_empty function.
 */
bool jq_is_empty(jobqueue_t* jq) {
    return jq->head == jq->tail;
}

/* 
 * TODO: you must implement this function.
 */
bool jq_is_full(jobqueue_t *jq) {
    if ((jq->head == 0 && jq->tail == jq->buf_size - 1) ||
        (jq->head > 0 && jq->tail == jq->head - 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* 
 * DO NOT EDIT the jq_peekhead function.
 */
job_t jq_peekhead(jobqueue_t* jq) {
    return jq->jobs[jq->head];
}

/* 
 * TODO: you must implement this function.
 *
 * Hints
 * - this is not quite as obvious as the peekhead function because the queue
 *      tail value is the position of the next available slot, not the slot
 *      for the value at the end of the queue
 * - remember the buffer wraps round and so the tail could be the position
 *      behind element 0 in the buffer etc
 */
job_t jq_peektail(jobqueue_t* jq) {
    if (jq->head == jq->tail)
        return UNUSED_ENTRY;
    else {
        if (jq->tail == 0) // we have just wrapped around.
            return jq->jobs[jq->buf_size - 1];
        else // return one entry before the tail position.
            return jq->jobs[jq->tail - 1];
    }
}

/* 
 * TODO: you must implement this function.
 */
void jq_delete(jobqueue_t* jq) {
    free(jq);
    jq = NULL;
}
