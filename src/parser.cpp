#include "error/Errors.h"
#include "lexical_analyser.h"
#include "symbols.h"
#include <iostream>
#include "general_parser.h"

//int main(int argc, char *argv[]) { 
//    Lexical::open_file(argv);
//    
//    Token* token = Lexical::get_token();
//    while (token != NULL) {
//        std::cout << token->lexem << std::endl;
//        token = Lexical::get_token();
//    }
//    Lexical::close_file();
//    return 0;
//}

int main(int argc, char *argv[]) {

    Lexical::open_file(argv);
    Token* token;

    //rotulo := 1
    token = Lexical::get_token();

    if (token->symbol == Symbols::SPROGRAMA) {

        token = Lexical::get_token();
        if (token->symbol == Symbols::SIDENTIFICADOR) {

            //insere_tabela(token.lexema,"nomedeprograma", "", "")
            
            token = Lexical::get_token();
            if (token->symbol == Symbols::SPONTO_VIRGULA) {

                //analisa_bloco
                Parser::snippet_analyser();
                // token = Lexical::get_token();

                if (token->symbol == Symbols::SPONTO) {
                    token = Lexical::get_token();
                    if (token != NULL) raiseError(Error::EXPECTED_EOF);
                } else {
                    raiseError(Error::EXPECTED_DOT);
                }
            } else {
                raiseError(Error::EXPECTED_SEMICOLON);
            }
        } else {
            raiseError(Error::EXPECTED_IDENTIFIER);
        }
    } else {
        raiseError(Error::EXPECTED_RESERVED_WORD_PROGRAMA);
    }

    Lexical::close_file();
    
    return 0;
}
