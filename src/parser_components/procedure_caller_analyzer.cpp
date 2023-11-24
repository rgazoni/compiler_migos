#include "../token/symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "lexical_analyzer.h"
#include "../parser_components/parser_components.h"
#include "generate.h"
#include "symbol_table.h"

using namespace std;

namespace Parser{
    void procedure_caller_analyzer(){ 
        Symbol_table symbol_table;
        Lexical lexical = Lexical();
        int label;

        cout << "procedimento: " << lexical.get_current_token().lexem << endl;

        // if(!symbol_table.is_procedure_exists(lexical.get_current_token().lexem)) {
        //     label = symbol_table.get_procedure_label(lexical.get_current_token().lexem);
        //     generate("", "CALL", to_string(label), "");
        // }

        // procura na tabela de simbolos algo correspondente a um procedimento == token atual
        // diorecionar execução para o procedimento em sí

        // lexical.next_token();

    }
}