objects/ipc_jobqueue.o: ipc_jobqueue.c ipc_jobqueue.h jobqueue.h job.h ipc.h \
  proc.h shobject_name.h | objects
	$(CC) -c $(CFLAGS) $< -o $@
