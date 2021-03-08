objects/job.o: job.c job.h | objects
	$(CC) -c $(CFLAGS) $< -o $@
