 #include "symbols.h"
 #include "./error/Errors.h"
 #include <fstream>
 #include <iostream>
 #include "lexical_analyzer.h"
 #include "parser_components.h"

namespace Parser{
    void conditional_analyzer() {
        Lexical lexical = Lexical();

        lexical.next_token();
        Parser::expression_analyzer();
        if (lexical.get_current_token().symbol == Symbols::SENTAO) {
            lexical.next_token();
            Parser::simple_command_analyzer();
            if (lexical.get_current_token().symbol == Symbols::SSENAO) {
                lexical.next_token();
                Parser::simple_command_analyzer();
            } 
        }else {
            raiseError(Error::EXPECTED_SENTAO);
        }
    }
}
