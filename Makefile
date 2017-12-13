CFLAGS = -ansi -pedantic -std=c99 -Wall -Wextra
HFILES = linked_list.h main.h
OFILES = linked_list.o main.o
CC = gcc

linked_list: $(OFILES)
	$(CC) $(CFLAGS) -o linked_list $(OFILES)
	
linked_list.o: linked_list.c $(HFILES)
	$(CC) $(CFLAGS) -c linked_list.c

main.o: main.c $(HFILES)
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f $(OFILES)