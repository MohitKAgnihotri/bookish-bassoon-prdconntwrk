objects/ipc.o: ipc.c ipc.h proc.h shobject_name.h | objects
	$(CC) -c $(CFLAGS) $< -o $@
