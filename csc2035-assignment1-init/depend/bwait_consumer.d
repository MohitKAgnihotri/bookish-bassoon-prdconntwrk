objects/bwait_consumer.o: bwait_consumer.c joblog.h job.h proc.h ipc_jobqueue.h \
  jobqueue.h ipc.h shobject_name.h mutex.h | objects
	$(CC) -c $(CFLAGS) $< -o $@
