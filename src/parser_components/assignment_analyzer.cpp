#include "../symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "lexical_analyser.h"
#include "../parser_components/general_parser.h"

namespace Parser{
    void assignment_analyzer() {
        Lexical lexical = Lexical();
        lexical.next_token();
        Parser::expression_analyser();
    }
}