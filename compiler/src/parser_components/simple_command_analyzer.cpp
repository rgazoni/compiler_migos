#include "../token/symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "lexical_analyzer.h"
#include "../parser_components/parser_components.h"

namespace Parser {
    void simple_command_analyzer () {
        Lexical lexical = Lexical();
        // cout << "quem é: " << lexical.get_current_token().lexem << " - symbol: " << symbolToString(lexical.get_current_token().symbol) << endl;

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