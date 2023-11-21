#include <iostream>

#include "../parser_components/parser_components.h"
#include "error/Errors.h"
#include "lexical/lexical_analyzer.h"
#include "symbols.h"
#include "symbol_table.h"

int main(int argc, char *argv[]) {
    Lexical lexical = Lexical();
    Symbol_table symbol_table = Symbol_table();
    lexical.open_file(argv);
    //Token* token;
    // rotulo := 1
    lexical.next_token();

    if (lexical.get_current_token().symbol == Symbols::SPROGRAMA) {
        lexical.next_token();
        
        if (lexical.get_current_token().symbol == Symbols::SIDENTIFICADOR) {            
            Record record(lexical.get_current_token().lexem, "SPROGRAMA", true, 0 );
            symbol_table.insert_record_procedure(&record);
            //symbol_table.print_table();
            lexical.next_token();
            if (lexical.get_current_token().symbol == Symbols::SPONTO_VIRGULA) {
                Parser::snippet_analyzer();

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
        symbol_table.print_table();
        lexical.close_file();

        return 0;
}

