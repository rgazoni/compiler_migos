#include "../token/symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "lexical_analyzer.h"
#include "../parser_components/parser_components.h"
#include "expression_builder.h"
#include "generate.h"

namespace Parser {
    void atribution_and_call_procedure(){
        Lexical lexical = Lexical();
        Expr_builder expr_builder = Expr_builder();
        Token token = lexical.get_current_token();
        
        lexical.next_token();

        if (lexical.get_current_token().symbol == Symbols::SATRIBUICAO) {
            //Analisa_atribuicao();
            //buscar na tabela de simbolos
            Parser::assignment_analyzer();
            expr_builder.infix_to_postfix();

            //buscar na tabela de simbolos para colocar o endereço no gera
            generate("", "STR", token.lexem, "");
        } else {
           //Chamada_procedimento();
           Parser::procedure_caller_analyzer();
        }
    }
}
