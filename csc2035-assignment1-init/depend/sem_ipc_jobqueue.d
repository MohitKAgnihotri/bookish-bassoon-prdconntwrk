objects/sem_ipc_jobqueue.o: sem_ipc_jobqueue.c sem_ipc_jobqueue.h ipc_jobqueue.h \
  jobqueue.h job.h ipc.h proc.h shobject_name.h | objects
	$(CC) -c $(CFLAGS) $< -o $@
