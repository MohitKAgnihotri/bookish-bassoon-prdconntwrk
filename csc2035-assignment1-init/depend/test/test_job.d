objects/test/test_job.o: test/test_job.c test/test_job.h test/munit.h test/../job.h | objects/test
	$(CC) -c $(CFLAGS) $< -o $@
