#include "symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "lexical_analyzer.h"
#include "parser_components.h"
#include "expression_builder.h"

namespace Parser{
    void expression_analyzer(){
        Lexical lexical = Lexical();
        Expr_builder expr_builder = Expr_builder();
        
        Parser::simple_expression_analyzer();
        if (lexical.get_current_token().symbol == Symbols::SMAIOR || lexical.get_current_token().symbol == Symbols::SMAIORIG || 
            lexical.get_current_token().symbol == Symbols::SIG || lexical.get_current_token().symbol == Symbols::SMENOR || 
            lexical.get_current_token().symbol == Symbols::SMENORIG || lexical.get_current_token().symbol == Symbols::SDIF) {
            expr_builder.add_to_array(lexical.get_current_token(), Symbols::SINTEIRO);

            lexical.next_token();
            Parser::simple_expression_analyzer();        
        }
    }
}

