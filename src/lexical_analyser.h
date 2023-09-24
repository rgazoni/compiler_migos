#include "Token.h"
#include <iostream>

#ifndef lexical_analyser_h
#define lexical_analyser_h

namespace Lexical {
    void open_file(char *argv[]);
    void close_file();
    int get_execution_line();
    int get_execution_column();
    Token* get_token();
}

void get_character_from_file();
void unnecessary_characters_dump();
Token* handle_reserved_words_and_identifiers();
Token* handle_digit();
Token* handle_aritmethic_operator();
Token* handle_assignment();
Token* handle_relational_operator();
Token* handle_punctuation();

#endif /* lexical_analyser_h */
