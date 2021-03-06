/******** DO NOT EDIT THIS FILE ********/
#ifndef _JOBQUEUE_H
#define _JOBQUEUE_H
#include <stddef.h>
#include <stdbool.h>
#include "job.h"

#define JOBQ_BUF_SIZE 128   /* size of the buffer used by a job queue */

/* 
 * The value for an unused entry in queue. If a queue slot has this entry
 * then it is considered unused. This value is also used as a return value
 * when there is no entry in the queue corresponding to a valid entry 
 * (e.g. returned from jq_dequeue, jq_peekhead and jq_peektail)
 *
 * UNUSED_ENTRY is set to {-1, -1} in jobqueue.c.
 */
extern const job_t UNUSED_ENTRY;

/* 
 * Introduction
 *
 * The job queue implementation uses a fixed sized job_t array as a circular
 * buffer.
 *
 * The jobqueue_t (alias for struct jobqueue) encapsulates the state of the
 * queue: head position, tail position, size and job_t buffer of jobs.
 *
 * The job queue is a FIFO queue, jobs are enqueued at the tail of the queue 
 * and dequeued at the head.
 *
 * The functions:
 *      jq_init
 *      jq_new
 *      jq_dequeue
 *      jq_enqueue
 *      jq_is_empty
 *      jq_is_full
 *      jq_peekhead
 *      jq_peektail
 *      jq_delete
 *
 * provide the operations on a jobqueue_t to create and initialise it, 
 * to test its state (empty, full, element at head and element at tail), 
 * to remove entries (dequeue), to add entries (enqueue) and to deallocate
 * resources associated with the queue.
 *
 * Together the functions above maintain the integrity of a job queue for
 * for single process access.
 *
 * IMPORTANT:
 * Only operate on a jobqueue using the functions defined in 
 * this file. Using a jobqueue in any other way can result in undefined 
 * and erroneous behaviour.
 */

/* 
 * Definition of struct jobqueue that can be used as the basic data structure
 * for sharing definitions of jobs between cooperating processes. 
 *
 * Type alias:
 * A struct jobqueue can also be referred to as jobqueue_t
 *
 * Fields:
 * head - the buffer index of the head of the queue
 * tail - the buffer index of the tail of the queue
 * buf_size - the size of the underlying buffer
 * jobs - the fixed sized buffer of job descriptions (job_t types) 
 *
 * Note fields of the struct should only be accessed in the implementation 
 * file jobqueue.c
 *
 * See also:
 * job.h - for information about the job descriptor type (job_t).
 */
typedef struct jobqueue {
    int head;
    int tail;
    int buf_size;
    job_t jobs[JOBQ_BUF_SIZE];
} jobqueue_t;

/*
 * jq_init(jobqueue_t* jq)
 *
 * Initialise a jobqueue to the following values:
 *      head - 0
 *      tail - 0
 *      bufs_size - JOB_BUF_SIZE
 * and all job entries in the buffer to the unused entry.
 * jq_init is a utility function to facilitate initialisation of shared memory 
 * versions of a jobqueue (see ipc_jobqueue). For single process versions, 
 * jq_new allocates and initialises the queue (by calling this function).
 * 
 * Calling jq_init on a queue that is in use will empty the queue. That is, 
 * the function can be used to initialise and re-initialise a queue.
 *
 * Usage:
 *      jobqueue_t* jq = ...        // create a jobqueue by some means
 *      jq_init(jq);                // initialise the jobqueue
 *
 * Parameters:
 * jq - a non-null pointer to a jobqueue to initialise
 *
 * Errors:
 * If jq is NULL a memory error will occur and the calling process will 
 * terminate. It is the responsibility of the programmer calling the function
 * to ensure that jq is not NULL.
 *
 * See also:
 * ipc_jobqueue - for further information on usage of jq_init
 */
void jq_init(jobqueue_t* jq);

/*
 * jq_new()
 *
 * Dynamically allocates and initialise a jobqueue.
 *
 * Usage:
 *      jobqueue_t* jq = jq_new();   // allocate a new job queue
 *      ...                          
 *      ...
 *      jq_delete(jq);               // delete the queue and release
 *                                   // resources associated with it
 *
 * Return:
 * On success: a new non-null pointer to a dynamically allocated jobqueue.
 *      Use jq_delete to free memory allocated to the jobqueue.
 * On failure: NULL, and errno is set as specified in Errors.
 *
 * Errors:
 * If the call fails, the NULL pointer will be returned and errno will be 
 * set as specified by system library dynamic memory allocation functions.
 * 
 * See also:
 * iq_init - for a description of initialisation of a jobqueue
 * job.h - for a description of the job type
 * man pages for malloc
 */
jobqueue_t* jq_new();

/*
 * jq_capacity(jobqueue_t* jq)
 *
 * Returns the capacity of the given queue - the maximum number of jobs that 
 * the queue can contain. A queue's capacity is set at its creation.
 *
 * Usage:
 *      jobqueue_t* jq = jq_new();
 *      int c = jq_capacity(jq);     // get the queue's capacity
 *      printf("%d\n", c);           // and print it to stdout                           
 *      ...
 *      jq_delete(jq);
 *
 * Parameters:
 * jq - a non-null pointer to a jobqueue
 *
 * Return:
 * The capacity of the queue (>= 1)
 *
 * Errors:
 * If jq is NULL a memory error will occur and the calling process will 
 * terminate. It is the responsibility of the programmer calling the function
 * to ensure that jq is not NULL.
 */
size_t jq_capacity(jobqueue_t* jq);

/* 
 * jq_dequeue(jobqueue_t* jq)
 *
 * If the queue is not empty, dequeues the job at the head of the queue (the
 * oldest job in the queue). On return of the function, the head is the next
 * job in the queue (or the queue is empty if the job dequeued was the only 
 * entry in the queue).
 * 
 * If the queue is empty, returns the unused entry. Calling dequeue on an 
 * empty queue has no effect on the state of the queue.
 * 
 * The user of this function can avoid the return of the unused entry by 
 * checking that the queue is not empty before calling dequeue.
 *
 * Usage:
 *      jobqueue_t* jq = jq_new();    
 *      ...
 *      ...
 *      while (!jq_is_empty(jq)) {      // dequeue jobs as long as the queue is 
 *          job_t j = jq_dequeue(jq);   // not empty
 *          ...
 *          ...
 *      }
 *      ...
 *      ...
 *      jq_delete(jq);  
 *
 * Parameters:
 * jq - a non-null pointer to a jobqueue
 *
 * Return:
 * The job at the head of the queue or, if the queue is empty, the unused 
 * entry. The returned job is a copy of the job that was at the head of the
 * queue. 
 
 * Important note:
 * If the queue was not empty, after the return of this function, the 
 * job at what was the head position will have been set to the unused entry and
 * the head position will have been advanced to the next job (which may result
 * in an empty queue).
 *
 * Errors:
 * If jq is NULL a memory error will occur and the calling process will 
 * terminate. It is the responsibility of the programmer calling the function
 * to ensure that jq is not NULL.
 *
 * See also:
 * job.h - for description of the job type
 */
job_t jq_dequeue(jobqueue_t* jq);

/*
 * jq_enqueue(jobqueue_t* jq, job_t j)
 *
 * If queue jq is not full, enqueues the given job on the given queue.
 * The job j is copied by value to the queue.
 *
 * If the queue jq is full, this function has no effect on the state of the 
 * state of the queue.
 *
 * Important notes:
 * 1. This function gives no indication that the queue is full. It silently
 *      fails if the queue is full. It is therefore the application 
 *      programmer's responsibility to check whether the queue is full 
 *      before calling this function.
 * 2. This function does not check the validity of the job enqueued. If the job
 *      has id values both set to -1 it will be indistinguishable from the 
 *      unused entry.
 *
 * Usage:
 *      jobqueue_t* jq = jq_new();    
 *      ...
 *      ...
 *      job_t j = { 0, 1 };
 *      while (!jq_is_full(jq)) {       // enqueue jobs as long as the queue is 
 *          jq_enqueue(jq, j);          // not full
 *          j.id++;
 *          ...
 *          ...
 *      }
 *      ...
 *      ...
 *      jq_delete(jq);  
 *
 * Parameters:
 * jq - a non-null pointer to a jobqueue
 * 
 * Errors:
 * If jq is NULL a memory error will occur and the calling process will 
 * terminate. It is the responsibility of the programmer calling the function
 * to ensure that jq is not NULL.
 *
 * See also:
 * job.h - for description of the job type
 */
void jq_enqueue(jobqueue_t* jq, job_t j);

/* 
 * jq_is_full(jobqueue_t* jq)
 *
 * Returns true if the queue is full, the number of jobs in the queue has 
 * reached its capacity, and false otherwise.
 *
 * Usage:
 *      jobqueue_t* jq = jq_new(); 
 *      ...
 *      ...
 *      job_t j = { 0, 1 };
 *      while (!jq_is_full(jq)) {       // enqueue jobs as long as the queue is 
 *          jq_enqueue(jq, j);          // not full
 *          j.id++;
 *          ...
 *          ...
 *      }
 *      ...
 *      ...
 *      jq_delete(jq);  
 *
 * Parameters:
 * jq - a non-null pointer to a jobqueue
 *
 * Return:
 * True if the queue is full, false otherwise.
 *
 * Errors:
 * If jq is NULL a memory error will occur and the calling process will 
 * terminate. It is the responsibility of the programmer calling the function
 * to ensure that jq is not NULL.
 */
bool jq_is_full(jobqueue_t* jq);

/*
 * jq_is_empty(jobqueue_t* jq)
 *
 * Returns true if the queue is empty, all slots are unused, and false
 * otherwise.
 *
 * Usage:
 *      jobqueue_t* jq = jq_new();    
 *      ...
 *      ...
 *      while (!jq_is_empty(jq)) {      // dequeue jobs as long as the queue is 
 *          job_t j = jq_dequeue(jq);   // not empty
 *          ...
 *          ...
 *      }
 *      ...
 *      ...
 *      jq_delete(jq);  
 *
 * Parameters:
 * jq - a non-null pointer to a jobqueue
 *
 * Return:
 * True if the queue is empty, false otherwise.
 *
 * Errors:
 * If jq is NULL a memory error will occur and the calling process will 
 * terminate. It is the responsibility of the programmer calling the function
 * to ensure that jq is not NULL.
 */
bool jq_is_empty(jobqueue_t* jq);

/*
 * jq_peekhead(jobqueue_t* jq)
 *
 * Returns the job at the head of the queue without dequeueing it. If the 
 * queue is empty when jq_peekhead is called, the unused entry will be 
 * returned. The caller can check whether the queue is empty prior 
 * to calling jq_peekhead to avoid the return of the unused entry job.
 *
 * This function does not change the state of the queue.
 *
 *
 * Usage:
 *      jobqueue_t* jq = jq_new();
 *      ...    
 *      ...
 *      if (!jq_is_empty(jq))
 *          job_t job_at_head = jq_peekhead(jq);  
 *                                  // the queue's state is unchanged 
 *                                  // job_at_head remains on the queue
 *      ...
 *      ...
 *      jq_delete(jq);  
 *
 * Parameters:
 * jq - a non-null pointer to a jobqueue
 *
 * Return:
 * The job at the head of the queue or the unused entry
 * if the queue is empty. The returned job is a copy of the job at 
 * the head of the queue, which remains on the queue. This function does 
 * not change the state of the queue.
 *
 * Errors:
 * If jq is NULL a memory error will occur and the calling process will 
 * terminate. It is the responsibility of the programmer calling the function
 * to ensure that jq is not NULL.
 */
job_t jq_peekhead(jobqueue_t* jq);

/*
 * jq_peektail(jobqueue_t* jq)
 *
 * Returns the job at the tail of the queue without dequeueing it. If the 
 * queue is empty when jq_peektail is called, the unused entry will be 
 * returned. The caller can check whether the queue is empty prior to 
 * calling jq_peektail to avoid the return of the unused entry.
 *
 * This function does not change the state of the queue.
 *
 * Usage:
 *      jobqueue_t* jq = jq_new();
 *      ...    
 *      ...
 *      if (!jq_is_empty(jq))
 *          job_t job_at_tail = jq_peektail(jq);  
 *                                  // the queue's state is unchanged 
 *                                  // job_at_tail remains on the queue
 *      ...
 *      ...
 *      jq_delete(jq);  
 *
 * Parameters:
 * jq - a non-null pointer to a jobqueue
 *
 * Return:
 * The job at the tail of the queue or the unused entry
 * if the queue is empty. The returned job is a copy of the job at 
 * the tail of the queue, which remains on the queue. This function does 
 * not change the state of the queue.
 *
 * Errors:
 * If jq is NULL a memory error will occur and the calling process will 
 * terminate. It is the responsibility of the programmer calling the function
 * to ensure that jq is not NULL.
 */
job_t jq_peektail(jobqueue_t* jq);

/*
 * jq_delete(jobqueue_t* jq)
 * 
 * This function frees resources allocated by jq_new.
 *
 * Parameters:
 * jq - a non-null pointer to the mutex to release
 *
 * Return:
 * There is no return value for the function. If jq is not NULL and the call 
 * succeeds, the queue will be freed. If jq is NULL this function has no effect.
 */
void jq_delete(jobqueue_t* jq);

#endif