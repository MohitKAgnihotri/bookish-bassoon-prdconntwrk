objects/test/test_joblog.o: test/test_joblog.c test/test_joblog.h test/munit.h \
  test/procs4tests.h test/../proc.h test/../joblog.h test/../job.h | objects/test
	$(CC) -c $(CFLAGS) $< -o $@
