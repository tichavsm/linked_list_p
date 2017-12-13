CFLAGS = -ansi -pedantic -std=c99 -Wall -Wextra
HFILES = linked_list.h
OFILES = linked_list.o
CC = gcc

linked_list: $(OFILES)
	$(CC) $(CFLAGS) -o linked_list $(OFILES)
	
linked_list.o: linked_list.c $(HFILES)
	$(CC) $(CFLAGS) -c linked_list.c
	
clean:
	rm -f $(OFILES)