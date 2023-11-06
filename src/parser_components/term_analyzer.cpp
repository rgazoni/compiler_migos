#include "symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "lexical_analyzer.h"
#include "expression_builder.h"
#include "parser_components.h"

namespace Parser{
    void term_analyzer(){
        Lexical lexical = Lexical();
        Expr_builder expr_builder = Expr_builder();

        Parser::factor_analyzer();
        while(lexical.get_current_token().symbol == Symbols::SMULT || lexical.get_current_token().symbol == Symbols::SDIV || lexical.get_current_token().symbol == Symbols::SE){
            expr_builder.add_to_array(Expr_token(lexical.get_current_token().lexem, Type::Int));
            lexical.next_token();
            Parser::factor_analyzer();
        }
    }   
}

