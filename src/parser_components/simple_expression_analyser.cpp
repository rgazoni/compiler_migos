#include "symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "lexical_analyser.h"
#include "general_parser.h"

namespace Parser{
    void simple_expression_analyser(){
        Lexical lexical = Lexical();
        if((lexical.get_current_token().symbol == Symbols::SMENOS) || (lexical.get_current_token().symbol == Symbols::SMAIS) ){
            lexical.next_token();
        }
        Parser::term_analyser(); 
        while((lexical.get_current_token().symbol == Symbols::SMENOS) || (lexical.get_current_token().symbol == Symbols::SMAIS) || (lexical.get_current_token().symbol == Symbols::SOU)){
            lexical.next_token();
            Parser::term_analyser();
        }
   
    }
}