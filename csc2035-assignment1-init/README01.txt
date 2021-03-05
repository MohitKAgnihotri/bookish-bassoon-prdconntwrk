The initial project directory contains:
    - all the project source code (.c and .h files). The header (.h) files
        provide documentation
    - make files to build the project
    - README01.txt: this file
    - README_joblog_example.txt: an example job log file
    - README_test_init.txt: expected test output for the initial release of 
        the project
    - README_test_pass.txt: expected test output when all functions 
        pass tests
    - shell scripts (.sh files) for various purposes that will be 
        explained as the project develops - the most important during 
        development is runtests.sh (see below)
    - test directory containing unit test source code
        e.g. tests of joblog.c are in test/test_joblog.h and 
        test/test_joblog.c, where test_jlog_write_entry is the unit
        test of the jlog_write_entry function in joblog.c
    - depend directory of build dependencies (including test dependencies in 
        depend/test)
    - objects directory of compiled object files created when the project 
        is built
    - out directory for application/simulation logs
    - bin directory of compiled application and test binaries (in bin/test)
    
Your task is to provide correct implementations of the following functions.

    In ipc_jobqueue.c : 
        ipc_jq_capacity, ipc_jq_dequeue, ipc_jq_enqueue,    
        ipc_jq_is_empty, ipc_jq_is_full, ipc_jq_peekhead, ipc_jq_peektail,
        ipc_jq_delete
    as specified in ipc_jobqueue.h and the assignment specification.

    In joblog.c : 
        jlog_write_entry, jlog_read_entry, jlog_delete
    as specified in joblog.h and the assignment specification. Other functions
    in this file are implemented for you.

    In jobqueue.c : 
        jq_new, jq_capacity, jq_dequeue, jq_is_full, jq_peektail, jq_delete
    as specified in jobqueue.h and the assignment specification

    In mutex_lockvar.c : 
        mu_enter, mu_delete
    as specified in mutex_lockvar.h and the assignment specification

    In mutex_peterson.c : 
        mu_new, mu_enter, mu_leave, mu_delete
    as specified in mutex_lockvar.h and the assignment specification

    In sem_ipc_jobqueue.c : 
        sem_ijq_capacity, sem_ijq_dequeue, sem_ijq_enqueue,    
        sem_ijq_is_empty, sem_ijq_is_full, sem_ijq_peekhead, sem_ijq_peektail,
        sem_ijq_delete
    as specified in sem_ipc_jobqueue.h and the assignment specification

    In shobject_name.c : 
        shobject_name
    as specified in shobject_name.h and the assignment specification

Each of the above functions has a dummy implementation to enable compilation.
These implementations should be replaced but do NOT change the function
signatures. Other functions in the above files may be implemented for you.
Looking at those other functions will help with the implementation of the 
above functions.

If you think it will help to reduce code duplication or simplify logic, you may
define your own helper functions in the above files. In which case,
they should be declared static to ensure they are private to the given 
compilation unit.

Hints for the implementations are provided in comments to each function.
As noted in the assignment specification, start with implementation of
joblog.c, shmobject.c and jobqueue.c (after first building the project and 
running tests - see below).

You can, and should, look at other files but do NOT edit, or delete,
other files and do NOT edit functions other than those listed above.

First, build the project and run the project tests, as in the following
instructions.

Note, building the project may give compilation errors. It is your job to fix
them if they are caused by code in files you have edited. If they are caused by 
code in other files, then report them using the programming support form
accessed from Canvas.

-----------------------------------------------------------------------------

To BUILD THE PROJECT (including tests), in the project directory type the 
following at the terminal command line prompt:

    make

This will build all project binaries.

If you get unexpected errors, try:

    make clean
    make

instead.

To RUN ALL TESTS, in the directory type the following at the terminal command
line prompt:

    ./runtests.sh 

To run individual tests type:

    ./bin/test/test_<module_name>

where <module_name> is replaced by the module you want to test. For example:

    ./bin/test/test_joblog

to run joblog tests.

-----------------------------------------------------------------------------

SUMMARY

When you first download and extract the project, cd to the project directory 
and type the following at the terminal command line prompt:

    make
    ./runtests.sh
    
this will build the project and run all tests.

The output of runtests.sh for the intitial project distribution should be 
similar to that shown in README_test_init.txt. 

Once you are working normally on the project you can just do:

    make 
    ./runtests.sh
    
when you just want to re-build the project and run tests.

Or:

    make clean
    make
    ./runtests.sh
    
if the making without cleaning temporary directories and binaries seems to 
cause unexpected errors.

Remember, "make" may give compilation errors. It is your job to fix them
if they are caused by code in files you have edited. If they are caused by 
code in other files, then report them using the programming support form
accessed from Canvas.

-----------------------------------------------------------------------------


