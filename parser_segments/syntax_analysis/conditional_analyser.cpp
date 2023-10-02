 #include "symbols.h"
 #include "./error/Errors.h"
 #include <fstream>
 #include <iostream>
 #include "lexical_analyser.h"
 #include "general_parser.h"

namespace Parser{
    void conditional_analyser(){
        Lexical lexical = Lexical();
        lexical.next_token();
        Parser::expression_analyser();
        if(lexical.get_current_token().symbol == Symbols::SENTAO){
            lexical.next_token();
            //Parser::simple_command_analyzer();
            if(lexical.get_current_token().symbol == Symbols::SSENAO){
                lexical.next_token();
                //Parser::simple_command_analyzer();
            }else{
                //erro
            }
        }
    }
}
