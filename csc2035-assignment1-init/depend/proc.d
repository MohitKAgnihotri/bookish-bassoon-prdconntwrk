objects/proc.o: proc.c proc.h | objects
	$(CC) -c $(CFLAGS) $< -o $@
