#include "symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include <any>
#include "lexical_analyzer.h"
#include "parser_components.h"


namespace Parser{
    void type_analyzer(){
        Lexical lexical = Lexical();

        if(lexical.get_current_token().symbol != Symbols::SINTEIRO && lexical.get_current_token().symbol != Symbols::SBOOLEANO){
            raiseError(Error::EXPECTED_BOOLEAN_OR_INT);
        }else{
            //coloca_tipo_tabela(token->lexem);
            if(lexical.get_current_token().symbol == Symbols::SINTEIRO){
                for(any element : any_variables){
                    integer_variables.push_back(any_cast<int>(element));
                }
            } else if(lexical.get_current_token().symbol == Symbols::SBOOLEANO){
                for(any element : any_variables){
                    boolean_variables.push_back(any_cast<bool>(element));
                }
            }

            lexical.next_token();
        }
    }
}
