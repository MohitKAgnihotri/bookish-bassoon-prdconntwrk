/******** DO NOT EDIT THIS FILE ********/
#include <stdio.h>
#include "test_jobqueue_common.h"
#include "test_ipc_jobqueue.h"
#include "../ipc_jobqueue.h"
#include "procs4tests.h"

int main(int argc, char** argv) {
    return munit_suite_main(&suite, NULL, argc, argv);
}

static void* test_setup(const MunitParameter params[], void* user_data) {
    test_jqueue_t* test_jq = (test_jqueue_t*) malloc(sizeof(test_jqueue_t));
    
    ipc_jobqueue_t* q = ipc_jq_new(new_init_proc());
    
    test_jq->q = q;
    jobqueue_t* jq = (jobqueue_t*) q->addr;
    
    test_jq->head = &jq->head;
    test_jq->tail = &jq->tail;
    test_jq->buf_size = &jq->buf_size;
    test_jq->jobs = jq->jobs;
    test_jq->capacity = (size_t (*)(void*)) ipc_jq_capacity;
    test_jq->is_full = (bool (*)(void*)) ipc_jq_is_full;
    test_jq->is_empty = (bool (*)(void*)) ipc_jq_is_empty;
    test_jq->enqueue = (void (*)(void*, job_t))  ipc_jq_enqueue;
    test_jq->dequeue = (job_t (*)(void*)) ipc_jq_dequeue;
    test_jq->peekhead = (job_t (*)(void*)) ipc_jq_peekhead;
    test_jq->peektail = (job_t (*)(void*)) ipc_jq_peektail;
        
    return test_jq;
}

static void test_tear_down(void* fixture) {
    test_jqueue_t* test_jq = (test_jqueue_t*) fixture;
    ipc_jobqueue_t* q = (ipc_jobqueue_t*) test_jq->q;
   
    proc_t* p = q->proc;
    ipc_jq_delete(q);
    proc_delete(p);
    free(test_jq);
}

static ipc_jobqueue_t* assert_ipc_jq_new(proc_t* p) {
    ipc_jobqueue_t* q = ipc_jq_new(p);
    assert_not_null(q);
    
    assert_init_jobqueue_state((jobqueue_t*) q->addr);
    
    return q;
}

static MunitResult test_ipc_jq_new_delete(const MunitParameter params[], 
    void* fixture) {
    test_procs_t* tp = new_test_procs();
    
    ipc_jobqueue_t* qin = assert_ipc_jq_new(tp->pin);
    ipc_jobqueue_t* qni = assert_ipc_jq_new(tp->pni);
    
    ipc_jq_delete(qni);
    
    ipc_jq_delete(qin);
    
    delete_test_procs(tp);
         
    return MUNIT_OK;
}

static MunitResult test_ipc_jq_capacity(const MunitParameter params[], 
    void* fixture) {
    return test_jqueue_capacity((test_jqueue_t*) fixture);
}

static MunitResult test_ipc_jq_is_full(const MunitParameter params[], 
    void* fixture) {
    return test_jqueue_is_full((test_jqueue_t*) fixture);
}

static MunitResult test_ipc_jq_is_empty(const MunitParameter params[],
    void* fixture) {
    return test_jqueue_is_empty((test_jqueue_t*) fixture);
}

static MunitResult test_ipc_jq_enqueue_dequeue(const MunitParameter params[], 
    void* fixture) {
    test_jqueue_t* test_jq = (test_jqueue_t*) fixture;
    ipc_jobqueue_t* q = (ipc_jobqueue_t*) test_jq->q;

    // test dequeuing from empty queue does not alter initial state
    assert_true(job_is_equal(test_jq->dequeue(q), UNUSED_ENTRY));
        
    assert_init_jobqueue_state((jobqueue_t*) q->addr);

    return test_jqueue_enqueue_dequeue((test_jqueue_t*) fixture);
}

static MunitResult test_ipc_jq_peekhead(const MunitParameter params[], 
    void* fixture) {
    return test_jqueue_peekhead((test_jqueue_t*) fixture);
}

static MunitResult test_ipc_jq_peektail(const MunitParameter params[], 
    void* fixture) {
    return test_jqueue_peektail((test_jqueue_t*) fixture);
}