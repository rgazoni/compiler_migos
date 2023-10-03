#include "../symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "lexical_analyser.h"
#include "../parser_components/general_parser.h"

namespace Parser {
    void simple_command_analyzer () {
        Lexical lexical = Lexical();
        if (lexical.get_current_token().symbol == Symbols::SIDENTIFICADOR) {
            Parser::atribution_and_call_procedure();
        } else if (lexical.get_current_token().symbol == Symbols::SSE) {
            Parser::conditional_analyzer();
        } else if (lexical.get_current_token().symbol == Symbols::SENQUANTO) {
            Parser::while_analyzer();
        } else if (lexical.get_current_token().symbol == Symbols::SLEIA) {
            Parser::read_analyzer();
        } else if (lexical.get_current_token().symbol == Symbols::SESCREVA) {
            Parser::write_analyzer();
        } else {
            Parser::command_analyzer();
        }
    }
}