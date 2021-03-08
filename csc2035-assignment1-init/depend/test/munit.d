objects/test/munit.o: test/munit.c test/munit.h | objects/test
	$(CC) -c $(CFLAGS) $< -o $@
