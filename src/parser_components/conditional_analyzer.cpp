#include "symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "lexical_analyzer.h"
#include "parser_components.h"
#include "expression_builder.h"
#include "generate.h"
#include "label.h"
#include "symbol_table.h"


namespace Parser{
    void conditional_analyzer() {
        Lexical lexical = Lexical();
        Expr_builder expr_builder = Expr_builder();
        Symbol_table symbol_table;

        lexical.next_token();
        Parser::expression_analyzer();
        expr_builder.infix_to_postfix();
        // symbol_table.print_table();

        string auxrot1, auxrot2;
        auxrot1 = Label::getLabel();
        generate("", "JMPF", Label::getLabel(), "");
        Label::setLabel(Label::incrementLabel());

        if (lexical.get_current_token().symbol == Symbols::SENTAO) {
            lexical.next_token();
            Parser::simple_command_analyzer();

            auxrot2 = Label::getLabel();
            generate("", "JMP", auxrot2, "");
            generate(auxrot1, "NULL", "", "");
            if (lexical.get_current_token().symbol == Symbols::SSENAO) {
                lexical.next_token();
                Label::setLabel(Label::incrementLabel());
                Parser::simple_command_analyzer();
                generate(auxrot2, "NULL", "", "");

            } 
        }else {
            raiseError(Error::EXPECTED_SENTAO);
        }
    }
}
