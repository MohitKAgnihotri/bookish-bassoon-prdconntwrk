objects/test/test_mutex_lockvar.o: test/test_mutex_lockvar.c test/../mutex_lockvar.h \
  test/../mutex.h test/../ipc.h test/../proc.h test/../shobject_name.h \
  test/test_mutex_lockvar.h test/munit.h test/procs4tests.h | objects/test
	$(CC) -c $(CFLAGS) $< -o $@
