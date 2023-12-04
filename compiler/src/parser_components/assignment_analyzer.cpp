#include "../token/symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "lexical_analyzer.h"
#include "../parser_components/parser_components.h"
#include "expression_builder.h"
#include "generate.h"


namespace Parser{
    void assignment_analyzer() {
        Lexical lexical = Lexical();
        Expr_builder expr_builder = Expr_builder();

        //lexical.next_token();
        Parser::expression_analyzer();
        // expr_builder.infix_to_postfix();
        // generate("", "STR", lexical.get_current_token().lexem, "");

    }
}