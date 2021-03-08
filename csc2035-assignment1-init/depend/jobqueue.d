objects/jobqueue.o: jobqueue.c jobqueue.h job.h | objects
	$(CC) -c $(CFLAGS) $< -o $@
