#include "lexical_analyzer.h"
#include "Symbols.h"
#include "./error/Errors.h"
#include "symbol_table.h"

namespace Parser {
    void write_analyzer () {
        Lexical lexical = Lexical();
        Symbol_table symbol_table;
        lexical.next_token();
        if (lexical.get_current_token().symbol == Symbols::SABRE_PARENTESES) {
            lexical.next_token(); 
            if (lexical.get_current_token().symbol == Symbols::SIDENTIFICADOR) {
                //se pesquisa_declvarfunc_tabela(token.lexema)
                lexical.next_token(); 
                if (lexical.get_current_token().symbol == Symbols::SFECHA_PARENTESES) {
                    lexical.next_token();
                } else {
                    raiseError(Error::EXPECTED_CLOSE_PARENTHESIS);
                }
                //senao errror
            } else {
                raiseError(Error::EXPECTED_IDENTIFIER);
            }
        } else {
            raiseError(Error::EXPECTED_OPEN_PARENTHESIS);
        }
    }
}



