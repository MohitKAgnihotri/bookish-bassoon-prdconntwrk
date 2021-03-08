objects/sem_producer.o: sem_producer.c joblog.h job.h proc.h sem_ipc_jobqueue.h \
  ipc_jobqueue.h jobqueue.h ipc.h shobject_name.h | objects
	$(CC) -c $(CFLAGS) $< -o $@
