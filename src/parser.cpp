#include <iostream>
#include "expression_builder.h"
#include "../parser_components/parser_components.h"
#include "error/Errors.h"
#include "lexical/lexical_analyzer.h"
#include "symbols.h"
#include "expr_token.h"
#include "semantic_analyzer.h"
#include "dev_env/tests.h"

void parser(char *file_path){
    Lexical lexical = Lexical();
    lexical.open_file(file_path);

    // rotulo := 1
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
                    std::cout << lexical.get_current_token().lexem << std::endl;
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
    bool dev_flag = false;
    char* file_path;
    // Record record;
    // Symbol_table symbol_table = Symbol_table();

    for(int i = 0 ; i < argc ; i++){
        if(argv[i] == "--dev" || argv[i] == "-D"){
            dev_flag = true;
            //call tests functions from dev_env directory
            expression();
        }

        if((argv[i] == "--file" || argv[i] == "-f" ) && i+1 <= argc){
            file_path = argv[i+1];
        }

    }

    if(!dev_flag)
        parser(file_path);

    std::cout << "passou?" << std::endl;
    return 0;

}
