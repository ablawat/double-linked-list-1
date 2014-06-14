CC     = gcc
CFLAGS = -O2

test: test.o linked-list-int.o
	$(CC) $(CFLAGS) -o test test.o linked-list-int.o

test.o: test.c
	$(CC) $(CFLAGS) -c -o test.o test.c

linked-list-int.o: linked-list-int.c
	$(CC) $(CFLAGS) -c -o linked-list-int.o linked-list-int.c

clean:
	rm -f *.o
	rm -f test
