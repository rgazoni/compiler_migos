#include "../token/symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "lexical_analyzer.h"
#include "../parser_components/parser_components.h"

namespace Parser{
    void assignment_analyzer() {
        Lexical lexical = Lexical();
        lexical.next_token();
        Parser::expression_analyzer();
    }
}