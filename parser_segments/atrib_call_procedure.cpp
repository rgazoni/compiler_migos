#include "../symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "lexical_analyser.h"
#include "../parser_components/general_parser.h"

namespace Parser {
    void atribution_and_call_procedure(){
        Lexical lexical = Lexical();
        lexical.next_token();

        if (lexical.get_current_token().symbol == Symbols::SATRIBUICAO) {
            Analisa_atribuicao();
        } else {
            Chamada_procedimento();
        }
    }
}