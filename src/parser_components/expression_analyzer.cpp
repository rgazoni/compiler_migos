#include "symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "lexical_analyzer.h"
#include "parser_components.h"

namespace Parser{
    void expression_analyzer(){
        Lexical lexical = Lexical();
        Parser::simple_expression_analyzer();
        if (lexical.get_current_token().symbol == Symbols::SMAIOR || lexical.get_current_token().symbol == Symbols::SMAIORIG || 
            lexical.get_current_token().symbol == Symbols::SIG || lexical.get_current_token().symbol == Symbols::SMENOR || 
            lexical.get_current_token().symbol == Symbols::SMENORIG || lexical.get_current_token().symbol == Symbols::SDIF) {
            lexical.next_token();
            Parser::simple_expression_analyzer();        
        }
    }
}

