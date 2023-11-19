#include "../token/symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "lexical_analyzer.h"
#include "../parser_components/parser_components.h"
#include "generate.h"

namespace Parser {
    void atribution_and_call_procedure(){
        Lexical lexical = Lexical();
        Token token = lexical.get_current_token();
        
        lexical.next_token();

        if (lexical.get_current_token().symbol == Symbols::SATRIBUICAO) {
            //Analisa_atribuicao();
            Parser::assignment_analyzer();
            //buscar na tabela de simbolos para colocar o endereço no gera
            // generate("", "STR", token.lexem, "");
        } else {
           //Chamada_procedimento();
           Parser::procedure_caller_analyzer();
        }
    }
}
