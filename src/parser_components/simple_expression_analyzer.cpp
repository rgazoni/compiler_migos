#include "symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "lexical_analyzer.h"
#include "expression_builder.h"
#include "parser_components.h"

namespace Parser{
    void simple_expression_analyzer(){
        Lexical lexical = Lexical();
        Expr_builder expr_builder = Expr_builder();

        if((lexical.get_current_token().symbol == Symbols::SMENOS) || (lexical.get_current_token().symbol == Symbols::SMAIS) ){
            expr_builder.add_to_array(Expr_token(lexical.get_current_token().lexem, Type::Int));
            lexical.next_token();
        }
        Parser::term_analyzer(); 
        while((lexical.get_current_token().symbol == Symbols::SMENOS) || (lexical.get_current_token().symbol == Symbols::SMAIS) || (lexical.get_current_token().symbol == Symbols::SOU)){
            expr_builder.add_to_array(Expr_token(lexical.get_current_token().lexem, Type::Int));
            lexical.next_token();
            Parser::term_analyzer();
        }
   
    }
}