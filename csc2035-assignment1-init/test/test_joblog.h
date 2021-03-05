/******** DO NOT EDIT THIS FILE ********/
/* 
 * test_joblog.h - structures and function declarations for unit tests
 * of joblog functions.
 * 
 */  
#ifndef _TEST_JOBLOG_H
#define _TEST_JOBLOG_H
#define MUNIT_ENABLE_ASSERT_ALIASES
#include "munit.h"

static void* test_setup(const MunitParameter params[], void* user_data);
static void test_tear_down(void* fixture);
static MunitResult test_jlog_init(const MunitParameter params[],
    void* fixture);
static MunitResult test_jlog_write_entry(const MunitParameter params[],
    void* fixture);
static MunitResult test_jlog_read_entry(const MunitParameter params[],
    void* fixture);
static MunitResult test_jlog_delete(const MunitParameter params[], 
    void* fixture);

static MunitTest tests[] = {
    { "/test_jlog_init", test_jlog_init, NULL, NULL,
        MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_jlog_write_entry", test_jlog_write_entry, test_setup,
        test_tear_down, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_jlog_read_entry", test_jlog_read_entry, test_setup,
        test_tear_down, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_jlog_delete", test_jlog_delete, test_setup, test_tear_down,
        MUNIT_TEST_OPTION_NONE, NULL },
   { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
};

static const MunitSuite suite = {
    "/test_joblog", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE 
};    


#endif