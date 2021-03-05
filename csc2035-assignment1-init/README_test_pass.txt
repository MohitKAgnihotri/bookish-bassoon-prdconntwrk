The following is expected test output after correct implementation of the
functions specified in README01.txt. All tests now pass.

------------------------------------------------------
Running bin/test/test_ipc ...
Running test suite with seed 0xfd394dfd...
/test_ipc/test_ipc                   [ OK    ] [ 1.00067600 / 0.00028900 CPU ]
/test_ipc/test_ipc_err               [ OK    ] [ 0.00002100 / 0.00001900 CPU ]
2 of 2 (100%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_ipc_jobqueue ...
Running test suite with seed 0xd3151f78...
/test_ipc_jobqueue/test_ipc_jq_new_delete[ OK    ] [ 1.00014400 / 0.00012200 CPU ]
/test_ipc_jobqueue/test_ipc_jq_capacity[ OK    ] [ 0.00000400 / 0.00000200 CPU ]
/test_ipc_jobqueue/test_ipc_jq_is_full[ OK    ] [ 0.00000900 / 0.00000500 CPU ]
/test_ipc_jobqueue/test_ipc_jq_is_empty[ OK    ] [ 0.00000800 / 0.00000500 CPU ]
/test_ipc_jobqueue/test_ipc_jq_enqueue_dequeue[ OK    ] [ 0.00003100 / 0.00002800 CPU ]
/test_ipc_jobqueue/test_ipc_jq_peekhead[ OK    ] [ 0.00001700 / 0.00001400 CPU ]
/test_ipc_jobqueue/test_ipc_jq_peektail[ OK    ] [ 0.00001900 / 0.00001700 CPU ]
7 of 7 (100%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_job ...
Running test suite with seed 0xb5dbde34...
/test_job/test_job_is_equal          [ OK    ] [ 0.00000500 / 0.00000200 CPU ]
1 of 1 (100%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_joblog ...
Running test suite with seed 0x2ec79d9d...
/test_joblog/test_jlog_init          [ OK    ] [ 0.00031900 / 0.00029900 CPU ]
/test_joblog/test_jlog_write_entry   [ OK    ] [ 0.00358100 / 0.00309000 CPU ]
/test_joblog/test_jlog_read_entry    [ OK    ] [ 0.00187000 / 0.00140000 CPU ]
/test_joblog/test_jlog_delete        [ OK    ] [ 0.00032100 / 0.00031900 CPU ]
4 of 4 (100%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_jobqueue ...
Running test suite with seed 0x615cf64e...
/test_jobqueue/test_jq_new_delete    [ OK    ] [ 0.00002300 / 0.00001900 CPU ]
/test_jobqueue/test_jq_capacity      [ OK    ] [ 0.00000500 / 0.00000200 CPU ]
/test_jobqueue/test_jq_is_full       [ OK    ] [ 0.00000800 / 0.00000600 CPU ]
/test_jobqueue/test_jq_is_empty      [ OK    ] [ 0.00000800 / 0.00000600 CPU ]
/test_jobqueue/test_jq_enqueue_dequeue[ OK    ] [ 0.00002700 / 0.00002300 CPU ]
/test_jobqueue/test_jq_peekhead      [ OK    ] [ 0.00001300 / 0.00001100 CPU ]
/test_jobqueue/test_jq_peektail      [ OK    ] [ 0.00001600 / 0.00001300 CPU ]
7 of 7 (100%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_mutex_lockvar ...
Running test suite with seed 0x0904224a...
/test_mutex_lockvar/test_mu_new      [ OK    ] [ 1.00060100 / 0.00009700 CPU ]
/test_mutex_lockvar/test_mu_enter    [ OK    ] [ 1.00027300 / 0.00009900 CPU ]
/test_mutex_lockvar/test_mu_leave    [ OK    ] [ 1.00039900 / 0.00009100 CPU ]
3 of 3 (100%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_mutex_noop ...
Running test suite with seed 0xcb970fb7...
/test_mutex_noop/test_mu_new         [ OK    ] [ 0.00002100 / 0.00001800 CPU ]
/test_mutex_noop/test_mu_enter       [ OK    ] [ 0.00000400 / 0.00000000 CPU ]
/test_mutex_noop/test_mu_leave       [ OK    ] [ 0.00000400 / 0.00000100 CPU ]
3 of 3 (100%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_mutex_peterson ...
Running test suite with seed 0xea4248cf...
/test_mutex_peterson/test_mu_new     [ OK    ] [ 1.00044700 / 0.00017000 CPU ]
/test_mutex_peterson/test_mu_enter   [ OK    ] [ 1.00079000 / 0.00016800 CPU ]
/test_mutex_peterson/test_mu_leave   [ OK    ] [ 1.00092700 / 0.00016500 CPU ]
3 of 3 (100%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_proc ...
Running test suite with seed 0x75597fcc...
/test_util/test_proc_init            [ OK    ] [ 0.00006500 / 0.00006400 CPU ]
1 of 1 (100%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_sem_ipc_jobqueue ...
Running test suite with seed 0xa8474f7b...
/test_ipc_jobqueue/test_sem_ijq_new_delete[ OK    ] [ 1.00023800 / 0.00020000 CPU ]
/test_ipc_jobqueue/test_sem_ijq_capacity[ OK    ] [ 0.00000400 / 0.00000100 CPU ]
/test_ipc_jobqueue/test_sem_ijq_is_full[ OK    ] [ 0.00023400 / 0.00023100 CPU ]
/test_ipc_jobqueue/test_sem_ijq_is_empty[ OK    ] [ 0.00024200 / 0.00023900 CPU ]
/test_ipc_jobqueue/test_sem_ijq_peekhead[ OK    ] [ 0.00124800 / 0.00121900 CPU ]
/test_ipc_jobqueue/test_sem_ijq_peektail[ OK    ] [ 0.00118300 / 0.00116700 CPU ]
/test_ipc_jobqueue/test_sem_ijq_2proc_enqueue_dequeue[ OK    ] [ 1.00454500 / 0.00219300 CPU ]
/test_ipc_jobqueue/test_sem_ijq_2proc_peekhead...............................................................................................................................
[ OK    ] [ 6.91580500 / 0.01133900 CPU ]
/test_ipc_jobqueue/test_sem_ijq_2proc_peektail...............................................................................................................................
[ OK    ] [ 2.60723700 / 0.00096200 CPU ]
9 of 9 (100%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
------------------------------------------------------
Running bin/test/test_shobject_name ...
Running test suite with seed 0x85e0e16d...
/test_shobject_name/test_shobject_name[ OK    ] [ 0.00002000 / 0.00001700 CPU ]
1 of 1 (100%) tests successful, 0 (0%) test skipped.
------------------------------------------------------
