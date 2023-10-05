#include "symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "lexical_analyzer.h"
#include "parser_components.h"

namespace Parser{
    void term_analyzer(){
        Lexical lexical = Lexical();
        Parser::factor_analyzer();
        while(lexical.get_current_token().symbol == Symbols::SMULT || lexical.get_current_token().symbol == Symbols::SDIV || lexical.get_current_token().symbol == Symbols::SE){
            lexical.next_token();
            Parser::factor_analyzer();
        }
    }   
}

