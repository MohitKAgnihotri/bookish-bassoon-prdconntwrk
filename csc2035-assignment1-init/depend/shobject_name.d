objects/shobject_name.o: shobject_name.c shobject_name.h | objects
	$(CC) -c $(CFLAGS) $< -o $@
