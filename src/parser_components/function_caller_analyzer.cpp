#include "../symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "lexical_analyser.h"
#include "../parser_components/general_parser.h"

namespace Parser{
    void function_caller_analyzer(){
        Lexical lexical = Lexical();

        // procura na tabela de simbolos algo correspondente a um procedimento == token atual
        // diorecionar execução para o procedimento em sí
        lexical.next_token();
            
        
    }
}