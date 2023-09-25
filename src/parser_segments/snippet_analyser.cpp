#include "error/Errors.h"
#include "lexical_analyser.h"
#include "symbols.h"
#include <iostream>

int snippet_analyser(){
    Token* token; 

    token = Lexical::get_token();
    et_variable_analyser();
    

}