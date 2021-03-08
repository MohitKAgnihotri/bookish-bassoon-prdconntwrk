objects/test/test_jobqueue.o: test/test_jobqueue.c test/test_jobqueue_common.h \
  test/munit.h test/../job.h test/../jobqueue.h test/test_jobqueue.h | objects/test
	$(CC) -c $(CFLAGS) $< -o $@
