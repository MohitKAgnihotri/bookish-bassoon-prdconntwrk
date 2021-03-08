objects/test/test_ipc.o: test/test_ipc.c test/test_ipc.h test/munit.h test/../ipc.h \
  test/../proc.h test/../shobject_name.h test/procs4tests.h | objects/test
	$(CC) -c $(CFLAGS) $< -o $@
