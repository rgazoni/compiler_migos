#include "../token/symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "lexical_analyzer.h"
#include "../parser_components/parser_components.h"
#include "generate.h"
#include "symbol_table.h"

namespace Parser{
    void function_caller_analyzer(){
        Symbol_table symbol_table;
        Lexical lexical = Lexical();
        int label;
        
        // label = symbol_table.get_function_label(lexical.get_current_token().lexem);
        // if(label != 0)
        //     generate("", "CALL", to_string(label), ""); //tenho que gerar um LDV
        // procura na tabela de simbolos algo correspondente a um procedimento == token atual
        // diorecionar execução para o procedimento em sí
        //lexical.next_token();
    }
}