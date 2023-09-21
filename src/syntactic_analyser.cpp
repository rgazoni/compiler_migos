#include "lexical_analyser.h"
#include <iostream>

int main(int argc, char *argv[]) { 
    Lexical::open_file(argv);
    
    Token* token = Lexical::get_token();
    while (token != NULL) {
        std::cout << token->lexem << std::endl;
        token = Lexical::get_token();
    }
    Lexical::close_file();
    return 0;
}
