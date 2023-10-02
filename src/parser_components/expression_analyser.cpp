#include "symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "lexical_analyser.h"
#include "general_parser.h"

namespace Parser{
    void expression_analyser(){
        Lexical lexical = Lexical();
        Parser::simple_expression_analyser();
        if (lexical.get_current_token().symbol == Symbols::SMAIOR || lexical.get_current_token().symbol == Symbols::SMAIORIG || 
            lexical.get_current_token().symbol == Symbols::SIG || lexical.get_current_token().symbol == Symbols::SMENOR || 
            lexical.get_current_token().symbol == Symbols::SMENORIG || lexical.get_current_token().symbol == Symbols::SDIF) {
            lexical.next_token();
            Parser::simple_expression_analyser();
        }
    }
}

