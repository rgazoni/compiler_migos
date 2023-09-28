#include "symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "lexical_analyser.h"
#include "general_parser.h"

namespace Parser{
    void read_analyser(){
        Lexical lexical = Lexical();

        if(lexical.get_current_token().symbol == Symbols::SABRE_PARENTESES){
            lexical.next_token();
            if(lexical.get_current_token().symbol == Symbols::SIDENTIFICADOR){
                // então se pesquisa_declvar_tabela(token.lexema) 
                // então início (pesquisa em toda a tabela)
                    lexical.next_token();
                    if(lexical.get_current_token().symbol == Symbols::SFECHA_PARENTESES){
                        lexical.next_token();
                    } else{
                        raiseError(Error::EXPECTED_CLOSE_PARENTHESIS);
                    }
                // senão ERRO
            } else{
                raiseError(Error::EXPECTED_IDENTIFIER);
            }
        } else{
            raiseError(Error::EXPECTED_OPEN_PARENTHESIS);
        }   
    }
}