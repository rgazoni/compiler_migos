#include "lexical_analyser.h"
#include "Symbols.h"
#include "./error/Error.h"

void write_analyser () {
    Lexical lexical = Lexical();
   
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
