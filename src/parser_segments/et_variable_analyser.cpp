#include "symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "lexical_analyser.h"
#include "general_parser.h"


namespace Parser {
    void et_variable_analyser(Token* token){
        
        if(token->symbol == Symbols::SVAR){
            token = Lexical::get_token();

            if(token->symbol == Symbols::SIDENTIFICADOR){
                while(token->symbol == Symbols::SIDENTIFICADOR){
                    //variable_analyser
                    Parser::variables_analyser(token);
                    // token = Lexical::get_token();
                    if(token->symbol == Symbols::SPONTO_VIRGULA){
                        token = Lexical::get_token();

                    }else{

                        raiseError(Error::EXPECTED_SEMICOLON);
                    }
                }
            }else{
                raiseError(Error::EXPECTED_IDENTIFIER);
            }
        }
    }
}

