/******** DO NOT EDIT THIS FILE ********/
#include <stdio.h>
#include "test_jobqueue_common.h"
#include "test_jobqueue.h"

int main(int argc, char** argv) {
    return munit_suite_main(&suite, NULL, argc, argv);
}

static void* test_setup(const MunitParameter params[], void* user_data) {
    test_jqueue_t* test_jq = (test_jqueue_t*) malloc(sizeof(test_jqueue_t));
    
    jobqueue_t* q = jq_new();
    test_jq->q = q;
    
    test_jq->head = &q->head;
    test_jq->tail = &q->tail;
    test_jq->buf_size = &q->buf_size;
    test_jq->jobs = q->jobs;
    test_jq->capacity = (size_t (*)(void*)) jq_capacity;
    test_jq->is_full = (bool (*)(void*))  jq_is_full;
    test_jq->is_empty = (bool (*)(void*)) jq_is_empty;
    test_jq->enqueue = (void (*)(void*, job_t))  jq_enqueue;
    test_jq->dequeue = (job_t (*)(void*))  jq_dequeue;
    test_jq->peekhead = (job_t (*)(void*))  jq_peekhead;
    test_jq->peektail = (job_t (*)(void*))  jq_peektail;
    
    return test_jq;
}

static void test_tear_down(void* fixture) {
    test_jqueue_t* test_jq = (test_jqueue_t*) fixture;
    jq_delete(test_jq->q);
    
    free(test_jq);
}

static MunitResult test_jq_new_delete(const MunitParameter params[], 
    void* fixture) {
    jobqueue_t* q = jq_new();
     
    assert_init_jobqueue_state(q);
    
    jq_delete(q);
    
    return MUNIT_OK;
}

static MunitResult test_jq_capacity(const MunitParameter params[], 
    void* fixture) {
    return test_jqueue_capacity((test_jqueue_t*) fixture);
}

static MunitResult test_jq_is_full(const MunitParameter params[], 
    void* fixture) {
    return test_jqueue_is_full((test_jqueue_t*) fixture);
}

static MunitResult test_jq_is_empty(const MunitParameter params[],
    void* fixture) {
    return test_jqueue_is_empty((test_jqueue_t*) fixture);
}

static MunitResult test_jq_enqueue_dequeue(const MunitParameter params[], 
    void* fixture) {
    test_jqueue_t* test_jq = (test_jqueue_t*) fixture;

    // test dequeuing from empty queue does not alter initial state
    assert_true(job_is_equal(test_jq->dequeue(test_jq->q), UNUSED_ENTRY));    
    assert_init_jobqueue_state((jobqueue_t*) test_jq->q);

    return test_jqueue_enqueue_dequeue((test_jqueue_t*) fixture);
}

static MunitResult test_jq_peekhead(const MunitParameter params[], 
    void* fixture) {
    return test_jqueue_peekhead((test_jqueue_t*) fixture);
}

static MunitResult test_jq_peektail(const MunitParameter params[], 
    void* fixture) {
    return test_jqueue_peektail((test_jqueue_t*) fixture);
}
