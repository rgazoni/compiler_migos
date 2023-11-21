#include "symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "lexical_analyzer.h"
#include "parser_components.h"
#include "generate.h"
#include "symbol_table.h"

namespace Parser{
    void read_analyzer(){
        Lexical lexical = Lexical();
        Token token;
        Symbol_table symbol_table;

        lexical.next_token();
        if(lexical.get_current_token().symbol == Symbols::SABRE_PARENTESES){
            lexical.next_token();
            if(lexical.get_current_token().symbol == Symbols::SIDENTIFICADOR){
                symbol_table.search_identifier(lexical.get_current_token().lexem);
                std::cout << "variavel da função leia: " <<lexical.get_current_token().lexem  << std::endl;
                // então se pesquisa_declvar_tabela(token.lexema) 
                // então início (pesquisa em toda a tabela)
                    token = lexical.get_current_token();
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

        generate("", "RD", "", "");
        generate("", "STR", token.lexem, "");
    }
}