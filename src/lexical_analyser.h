#include "Token.h"
#include <iostream>

#ifndef lexical_analyser_h
#define lexical_analyser_h

namespace Lexical {
    void open_file(char *argv[]);
    void close_file();
    Token* get_token();
}

void unnecessary_characters_dump(char *c, std::ifstream &file);
Token* handle_reserved_words_and_identifiers(char *c, std::ifstream &file);
Token* handle_digit(char *c, std::ifstream &file);
Token* handle_aritmethic_operator(char *c, std::ifstream &file);
Token* handle_assignment(char *c, std::ifstream &file);
Token* handle_relational_operator(char *c, std::ifstream &file);
Token* handle_ponctuation(char *c, std::ifstream &file);

#endif /* lexical_analyser_h */
