objects/test/test_jobqueue_common.o: test/test_jobqueue_common.c \
  test/test_jobqueue_common.h test/munit.h test/../job.h \
  test/../jobqueue.h | objects/test
	$(CC) -c $(CFLAGS) $< -o $@
