CC=gcc

test: test.o linked-list-int.o
	$(CC) -o test test.o linked-list-int.o

test.o: test.c
	$(CC) -c -o test.o test.c

linked-list-int.o: linked-list-int.c
	$(CC) -c -o linked-list-int.o linked-list-int.c

clean:
	find . -type f -name "*.o" | xargs rm -f
	find . -type f -perm /111  | xargs rm -f
