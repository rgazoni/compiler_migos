#include "symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "lexical_analyzer.h"
#include "parser_components.h"


namespace Parser {
    void et_variable_analyzer(){
        Lexical lexical = Lexical();

        if(lexical.get_current_token().symbol == Symbols::SVAR){
            lexical.next_token();

            if(lexical.get_current_token().symbol == Symbols::SIDENTIFICADOR){
                while(lexical.get_current_token().symbol == Symbols::SIDENTIFICADOR){
                    
                    Parser::variables_analyzer();
                    if(lexical.get_current_token().symbol == Symbols::SPONTO_VIRGULA){
                        lexical.next_token();

                    } else {
                        raiseError(Error::EXPECTED_SEMICOLON);
                    }
                }
            }else{
                raiseError(Error::EXPECTED_IDENTIFIER);
            }
        }
    }
}

