#include <iostream>
#include "expression_builder.h"
#include "../parser_components/parser_components.h"
#include "error/Errors.h"
#include "lexical/lexical_analyzer.h"
#include "symbols.h"
#include "expr_token.h"
#include "semantic_analyzer.h"
#include "expression_builder.h"
#include "dev_env/tests.h"

// int label;

void parser(char *file_path){
    Lexical lexical = Lexical();
    lexical.open_file(file_path);

    // rotulo := 1
    // label = 1;
    lexical.next_token();
    
    if (lexical.get_current_token().symbol == Symbols::SPROGRAMA) {
        lexical.next_token();
        
        if (lexical.get_current_token().symbol == Symbols::SIDENTIFICADOR) {            
            // insere_tabela(token->lexema,"nomedeprograma", "", "")
            lexical.next_token();
            if (lexical.get_current_token().symbol == Symbols::SPONTO_VIRGULA) {
                // analisa_bloco
                Parser::snippet_analyzer();
                // lexical.next_token();

                if (lexical.get_current_token().symbol == Symbols::SPONTO) {
                    lexical.next_token();
                    // std::cout << lexical.get_current_token().lexem << std::endl;
                    if (lexical.get_current_token().symbol !=
                        Symbols::END_OF_FILE)
                        raiseError(Error::EXPECTED_EOF);
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

    lexical.close_file();
}


int main(int argc, char *argv[]) {
    Lexical lexical = Lexical();
    Expr_builder expr_builder = Expr_builder();

    bool is_file_provided = false;
    char* file_path;

    for(int i = 0 ; i < argc ; i++){
        std::string arg = argv[i];

        if(arg == "--dev"|| arg == "-D"){
            //Call tests functions from dev_env directory
            expression2();
        }

        if((arg == "--file" || arg == "-f" ) && i+1 <= argc){
            is_file_provided = true;
            file_path = argv[i+1];
        }
    }

    if(is_file_provided)
        parser(file_path);
    else
        std::cout << "To run parser, a file must be provided with --file or -f." << std::endl;

    // for(Expr_token token : expr_builder.expr_array){
    //     std::cout << "lexem: " << token.lexem << std::endl;
    // }

    return 0;
}
