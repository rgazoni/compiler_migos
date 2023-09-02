CFLAGS = -O

CC = g++

output: lexical_analyser.o linked_list.o
	$(CC) $(CFLAGS) -o output lexical_analyser.o linked_list.o

lexical_analyser.o: lexical_analyser.cpp
	$(CC) $(CFLAGS) -c lexical_analyser.cpp

linked_list.o: linked_list.cpp
	$(CC) $(CFLAGS) -c linked_list.cpp

clean:
	rm -f core *.o a.out
