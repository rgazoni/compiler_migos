#include <fstream>
#include <iostream>

#include "../parser_components/parser_components.h"
#include "../token/symbols.h"
#include "./error/Errors.h"
#include "lexical_analyzer.h"

namespace Parser {
    void while_analyzer() {
        Lexical lexical = Lexical();

        // Def auxrot1, auxrot2 inteiro
        // Inicio
        // auxrot1 := rotulo
        // Gera(rotulo, NULL, ´ ´, ´ ´)
        // rotulo := rotulo + 1

        lexical.next_token();
        Parser::expression_analyzer();

        if (lexical.get_current_token().symbol == Symbols::SFACA) {
            // auxrot2 := rotulo
            // Gera(´ ´,  JMPF, rotulo, ´ ´) {salta se falso}
            // rotulo := rotulo + 1

            lexical.next_token();
            Parser::simple_command_analyzer();
            // Gera(´ ´, JMP, auxrot1, ´ ´) {retorna incio do loop}
            // Gera(auxrot2, NULL, ´ ´. ´ ´) {fim do while}
        } else {
            raiseError(Error::EXPECTED_IDENTIFIER);
        }
    }
}  