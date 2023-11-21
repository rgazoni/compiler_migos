#include "symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "lexical_analyzer.h"
#include "symbol_table.h"
#include "parser_components.h"
#include "expression_builder.h"

using namespace std;

namespace Parser{
    void type_analyzer(){
        Lexical lexical = Lexical();

        if(lexical.get_current_token().symbol != Symbols::SINTEIRO && lexical.get_current_token().symbol != Symbols::SBOOLEANO){
            raiseError(Error::EXPECTED_BOOLEAN_OR_INT);
        }else{
            symbol_table.update_variable_type(lexical.get_current_token().lexem);
            //coloca_tipo_tabela(token->lexem);

            //if so feito por via de testes

            if(lexical.get_current_token().symbol == Symbols::SINTEIRO){
                for(string element : expr_builder.any_variables){
                    expr_builder.integer_variables.push_back(element);
                }
            } else if(lexical.get_current_token().symbol == Symbols::SBOOLEANO){
                for(string element : expr_builder.any_variables){
                    expr_builder.boolean_variables.push_back(element);
                }
            }

            expr_builder.any_variables.clear();     
            lexical.next_token();
        }
    }
}
