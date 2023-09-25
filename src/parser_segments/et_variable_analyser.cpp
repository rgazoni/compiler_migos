#include "symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "lexical_analyser.h"


namespace Parser {
    int et_variable_analyser(){
        Token* token;
        token = Lexical::get_token();
        
        if(token->symbol == Symbols::SVAR){
            //lexic(token);
            if(token->symbol == Symbols::SIDENTIFICADOR){
                while(token->symbol == Symbols::SIDENTIFICADOR){
                    //variable_analyser
                    if(token->symbol == Symbols::SPONTO_VIRGULA){
                        //lexic(token);
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

