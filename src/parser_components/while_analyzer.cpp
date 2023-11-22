#include <fstream>
#include <iostream>

#include "../parser_components/parser_components.h"
#include "../token/symbols.h"
#include "./error/Errors.h"
#include "lexical_analyzer.h"
#include "generate.h"
#include "label.h"
#include "expression_builder.h"
#include "symbol_table.h"


namespace Parser {
    void while_analyzer() {
        Lexical lexical = Lexical();
        Expr_builder expr_builder = Expr_builder();
        Symbol_table symbol_table;


        // Def auxrot1, auxrot2 inteiro
        // Inicio
        // auxrot1 := rotulo
        // Gera(rotulo, NULL, ´ ´, ´ ´)
        // rotulo := rotulo + 1

        string auxrot1, auxrot2;
        auxrot1 = Label::getLabel();
        generate(Label::getLabel(), "NULL", "", "");
        Label::setLabel(Label::incrementLabel());

        lexical.next_token();
        Parser::expression_analyzer();
        
        expr_builder.infix_to_postfix();
        // symbol_table.print_table();

        if (lexical.get_current_token().symbol == Symbols::SFACA) {
            // auxrot2 := rotulo
            // Gera(´ ´,  JMPF, rotulo, ´ ´) {salta se falso}
            // rotulo := rotulo + 1

            auxrot2 = Label::getLabel();
            generate("", "JMPF", Label::getLabel(), "");
            Label::setLabel(Label::incrementLabel());


            lexical.next_token();
            Parser::simple_command_analyzer();
            // Gera(´ ´, JMP, auxrot1, ´ ´) {retorna incio do loop}
            // Gera(auxrot2, NULL, ´ ´. ´ ´) {fim do while}

            generate("", "JMP", auxrot1, "");
            generate(auxrot2, "NULL", "", "");

        } else {
            raiseError(Error::EXPECTED_IDENTIFIER);
        }
    }
}  