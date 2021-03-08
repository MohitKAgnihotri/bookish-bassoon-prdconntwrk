objects/test/test_mutex_noop.o: test/test_mutex_noop.c test/../mutex_noop.h \
  test/../mutex.h test/../ipc.h test/../proc.h test/../shobject_name.h \
  test/test_mutex_noop.h test/munit.h test/procs4tests.h | objects/test
	$(CC) -c $(CFLAGS) $< -o $@
