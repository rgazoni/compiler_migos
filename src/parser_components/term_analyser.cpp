#include "symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "lexical_analyser.h"
#include "general_parser.h"

namespace Parser{
    void term_analyser(){
        Lexical lexical = Lexical();
        Parser::factor_analyser();
        while(lexical.get_current_token().symbol == Symbols::SMULT || lexical.get_current_token().symbol == Symbols::SDIV || lexical.get_current_token().symbol == Symbols::SE){
            lexical.next_token();
            Parser::factor_analyser();
        }
    }   
}
