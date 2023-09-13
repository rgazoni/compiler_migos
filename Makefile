CFLAGS = -O

CC = g++

lex_anal_exec: lexical_analyser.o linked_list.o symbol_table.o
	$(CC) $(CFLAGS) -o lex_anal_exec lexical_analyser.o linked_list.o symbol_table.o

lexical_analyser.o: lexical_analyser.cpp
	$(CC) $(CFLAGS) -c lexical_analyser.cpp

linked_list.o: linked_list.cpp
	$(CC) $(CFLAGS) -c linked_list.cpp

symbol_table.o: symbol_table.cpp
	$(CC) $(CFLAGS) -c symbol_table.cpp
clean:
	rm -f core *.o a.out
