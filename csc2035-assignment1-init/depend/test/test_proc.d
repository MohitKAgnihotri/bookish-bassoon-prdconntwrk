objects/test/test_proc.o: test/test_proc.c test/test_proc.h test/munit.h \
  test/../proc.h | objects/test
	$(CC) -c $(CFLAGS) $< -o $@
