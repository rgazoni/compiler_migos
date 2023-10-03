#include <iostream>

#include "../parser_components/general_parser.h"
#include "error/Errors.h"
#include "lexical_analyser.h"
#include "symbols.h"

int main(int argc, char *argv[]) {
    Lexical lexical = Lexical();

    lexical.open_file(argv);
    // Token* token;

    // rotulo := 1
    lexical.next_token();

    if (lexical.get_current_token().symbol == Symbols::SPROGRAMA) {
        lexical.next_token();
        if (lexical.get_current_token().symbol == Symbols::SIDENTIFICADOR) {
            // insere_tabela(token->lexema,"nomedeprograma", "", "")

            lexical.next_token();
            if (lexical.get_current_token().symbol == Symbols::SPONTO_VIRGULA) {
                // analisa_bloco
                //Parser::snippet_analyser();
                Parser::while_analyzer();
                // lexical.next_token();

                if (lexical.get_current_token().symbol == Symbols::SPONTO) {
                    lexical.next_token();
                    std::cout << lexical.get_current_token().lexem << std::endl;
                    if (lexical.get_current_token().symbol !=
                        Symbols::END_OF_FILE)
                        raiseError(Error::EXPECTED_EOF);
                } else {
                    raiseError(Error::EXPECTED_DOT);
                }
            } else {
                raiseError(Error::EXPECTED_SEMICOLON);
            }
        } else {
            raiseError(Error::EXPECTED_IDENTIFIER);
        }
    } else {
        raiseError(Error::EXPECTED_RESERVED_WORD_PROGRAMA);
    }

    lexical.close_file();

    return 0;
}
