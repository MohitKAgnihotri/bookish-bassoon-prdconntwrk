objects/mutex_noop.o: mutex_noop.c mutex_noop.h mutex.h ipc.h proc.h \
  shobject_name.h | objects
	$(CC) -c $(CFLAGS) $< -o $@
