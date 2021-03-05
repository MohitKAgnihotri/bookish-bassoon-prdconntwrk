The following is expected test output (mostly errors) for the initial 
release of the project before the functions specified in README01.txt are 
implemented. Note: some of the error messages may differ on different 
machines.

------------------------------------------------------
Running bin/test/test_ipc ...
Running test suite with seed 0x686bbd1e...
/test_ipc/test_ipc                   [ ERROR ]
Error: test/test_ipc.c:67: assertion failed: ipc != ((void *)0) (0x0 != 0x0)
Error: test/test_ipc.c:98: assertion failed: ipc != ((void *)0) (0x0 != 0x0)
Error: child killed by signal 6
/test_ipc/test_ipc_err               [ OK    ] [ 0.00006500 / 0.00005100 CPU ]
1 of 2 (50%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_ipc_jobqueue ...
Running test suite with seed 0x19a3fe9c...
/test_ipc_jobqueue/test_ipc_jq_new_delete[ ERROR ]
Error: test/test_ipc_jobqueue.c:47: assertion failed: q != ((void*)0) (0x0 != 0x0)
Error: child killed by signal 6
/test_ipc_jobqueue/test_ipc_jq_capacity[ ERROR ]
Error: child killed by signal 11
/test_ipc_jobqueue/test_ipc_jq_is_full[ ERROR ]
Error: child killed by signal 11
/test_ipc_jobqueue/test_ipc_jq_is_empty[ ERROR ]
Error: child killed by signal 11
/test_ipc_jobqueue/test_ipc_jq_enqueue_dequeue[ ERROR ]
Error: child killed by signal 11
/test_ipc_jobqueue/test_ipc_jq_peekhead[ ERROR ]
Error: child killed by signal 11
/test_ipc_jobqueue/test_ipc_jq_peektail[ ERROR ]
Error: child killed by signal 11
0 of 7 (0%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_job ...
Running test suite with seed 0x4ad6109e...
/test_job/test_job_is_equal          [ OK    ] [ 0.00000700 / 0.00000200 CPU ]
1 of 1 (100%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_joblog ...
Running test suite with seed 0x10a6d91d...
/test_joblog/test_jlog_init          [ OK    ] [ 0.00013900 / 0.00013700 CPU ]
/test_joblog/test_jlog_write_entry   [ FAIL  ]
/test_joblog/test_jlog_read_entry    [ ERROR ]
Error: test/test_joblog.c:122: assertion failed: i == 11 (0 == 11)
Error: child killed by signal 6
/test_joblog/test_jlog_delete        [ ERROR ]
Error: test/test_joblog.c:240: assertion failed: (*__error()) == 0 (22 == 0)
Error: child killed by signal 6
1 of 4 (25%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_jobqueue ...
Running test suite with seed 0x5a0fcd93...
/test_jobqueue/test_jq_new_delete    [ ERROR ]
Error: test/test_jobqueue_common.c:91: assertion failed: jq != ((void*)0) (0x0 != 0x0)
Error: child killed by signal 6
/test_jobqueue/test_jq_capacity      [ ERROR ]
Error: child killed by signal 11
/test_jobqueue/test_jq_is_full       [ ERROR ]
Error: child killed by signal 11
/test_jobqueue/test_jq_is_empty      [ ERROR ]
Error: child killed by signal 11
/test_jobqueue/test_jq_enqueue_dequeue[ ERROR ]
Error: test/test_jobqueue_common.c:91: assertion failed: jq != ((void*)0) (0x0 != 0x0)
Error: child killed by signal 6
/test_jobqueue/test_jq_peekhead      [ ERROR ]
Error: child killed by signal 11
/test_jobqueue/test_jq_peektail      [ ERROR ]
Error: child killed by signal 11
0 of 7 (0%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_mutex_lockvar ...
Running test suite with seed 0x0df5b8c7...
/test_mutex_lockvar/test_mu_new      [ ERROR ]
Error: test/test_mutex_lockvar.c:21: assertion failed: m != ((void *)0) (0x0 != 0x0)
Error: child killed by signal 6
/test_mutex_lockvar/test_mu_enter    [ ERROR ]
Error: test/test_mutex_lockvar.c:21: assertion failed: m != ((void *)0) (0x0 != 0x0)
Error: child killed by signal 6
/test_mutex_lockvar/test_mu_leave    [ ERROR ]
Error: test/test_mutex_lockvar.c:21: assertion failed: m != ((void *)0) (0x0 != 0x0)
Error: child killed by signal 6
0 of 3 (0%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_mutex_noop ...
Running test suite with seed 0x15f9d232...
/test_mutex_noop/test_mu_new         [ OK    ] [ 0.00001600 / 0.00001300 CPU ]
/test_mutex_noop/test_mu_enter       [ OK    ] [ 0.00000400 / 0.00000100 CPU ]
/test_mutex_noop/test_mu_leave       [ OK    ] [ 0.00000400 / 0.00000200 CPU ]
3 of 3 (100%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_mutex_peterson ...
Running test suite with seed 0xea775861...
/test_mutex_peterson/test_mu_new     [ ERROR ]
Error: test/test_mutex_peterson.c:23: assertion failed: m != ((void *)0) (0x0 != 0x0)
Error: child killed by signal 6
/test_mutex_peterson/test_mu_enter   [ ERROR ]
Error: test/test_mutex_peterson.c:23: assertion failed: m != ((void *)0) (0x0 != 0x0)
Error: child killed by signal 6
/test_mutex_peterson/test_mu_leave   [ ERROR ]
Error: test/test_mutex_peterson.c:23: assertion failed: m != ((void *)0) (0x0 != 0x0)
Error: child killed by signal 6
0 of 3 (0%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_proc ...
Running test suite with seed 0x6ab48072...
/test_util/test_proc_init            [ OK    ] [ 0.00008600 / 0.00008300 CPU ]
1 of 1 (100%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_sem_ipc_jobqueue ...
Running test suite with seed 0x359a4dad...
/test_ipc_jobqueue/test_sem_ijq_new_delete[ ERROR ]
Error: test/test_sem_ipc_jobqueue.c:50: assertion failed: sijq != ((void*)0) (0x0 != 0x0)
Error: child killed by signal 6
/test_ipc_jobqueue/test_sem_ijq_capacity[ ERROR ]
Error: child killed by signal 11
/test_ipc_jobqueue/test_sem_ijq_is_full[ ERROR ]
Error: child killed by signal 11
/test_ipc_jobqueue/test_sem_ijq_is_empty[ ERROR ]
Error: child killed by signal 11
/test_ipc_jobqueue/test_sem_ijq_peekhead[ ERROR ]
Error: child killed by signal 11
/test_ipc_jobqueue/test_sem_ijq_peektail[ ERROR ]
Error: child killed by signal 11
/test_ipc_jobqueue/test_sem_ijq_2proc_enqueue_dequeue[ ERROR ]
Error: test/test_sem_ipc_jobqueue.c:145: assertion failed: sijq != ((void*)0) (0x0 != 0x0)
Error: test/test_sem_ipc_jobqueue.c:165: assertion failed: sijq != ((void*)0) (0x0 != 0x0)
Error: child killed by signal 6
/test_ipc_jobqueue/test_sem_ijq_2proc_peekhead[ ERROR ]
Error: test/test_sem_ipc_jobqueue.c:199: assertion failed: sijq != ((void*)0) (0x0 != 0x0)
Error: test/test_sem_ipc_jobqueue.c:227: assertion failed: sijq != ((void*)0) (0x0 != 0x0)
Error: child killed by signal 6
/test_ipc_jobqueue/test_sem_ijq_2proc_peektail[ ERROR ]
Error: test/test_sem_ipc_jobqueue.c:281: assertion failed: sijq != ((void*)0) (0x0 != 0x0)
Error: test/test_sem_ipc_jobqueue.c:306: assertion failed: sijq != ((void*)0) (0x0 != 0x0)
Error: child killed by signal 6
0 of 9 (0%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_shobject_name ...
Running test suite with seed 0xcb03baf4...
/test_shobject_name/test_shobject_name[ ERROR ]
Error: test/test_shobject_name.c:30: assertion failed: string actual_name == expected_name ("" == "/csc2035.nnoc.test")
Error: child killed by signal 6
0 of 1 (0%) tests successful, 0 (0%) test skipped.
------------------------------------------------------

