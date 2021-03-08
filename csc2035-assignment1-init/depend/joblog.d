objects/joblog.o: joblog.c joblog.h job.h proc.h | objects
	$(CC) -c $(CFLAGS) $< -o $@
