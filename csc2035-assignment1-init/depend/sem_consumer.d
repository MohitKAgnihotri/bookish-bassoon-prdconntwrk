objects/sem_consumer.o: sem_consumer.c joblog.h job.h proc.h sem_ipc_jobqueue.h \
  ipc_jobqueue.h jobqueue.h ipc.h shobject_name.h | objects
	$(CC) -c $(CFLAGS) $< -o $@
