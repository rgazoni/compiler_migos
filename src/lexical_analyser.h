#ifndef lexical_analyser_h
#define lexical_analyser_h

#include "Token.h"
#include <iostream>

class Lexical {
public:
    static Token* current_token;

    void open_file(char *argv[]);
    void close_file();
    int get_execution_line();
    int get_execution_column();
    Token get_current_token();
    void next_token();

private:
    static std::ifstream file;
    static char *c;
    static int execution_line;
    static int execution_column;

    void get_character_from_file();
    void unnecessary_characters_dump();
    void handle_reserved_words_and_identifiers();
    void handle_digit();
    void handle_aritmethic_operator();
    void handle_assignment();
    void handle_relational_operator();
    void handle_punctuation();
};

#endif /* lexical_analyser_h */
