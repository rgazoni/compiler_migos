#include "lexical_analyzer.h"
#include "Symbols.h"
#include "./error/Errors.h"
#include "generate.h"
#include "symbol_table.h"

namespace Parser {
    void write_analyzer () {
        Lexical lexical = Lexical();
        Token token;
        Symbol_table symbol_table;
        lexical.next_token();
        if (lexical.get_current_token().symbol == Symbols::SABRE_PARENTESES) {
            lexical.next_token(); 
            if (lexical.get_current_token().symbol == Symbols::SIDENTIFICADOR) {
                symbol_table.search_identifier(lexical.get_current_token().lexem);
                // std::cout << "variavel da função escreva: " <<lexical.get_current_token().lexem  << std::endl;
                //se pesquisa_declvarfunc_tabela(token.lexema)
                token = lexical.get_current_token();
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

        generate("", "LDV", token.lexem, "");
        generate("", "PRN", "", "");
    }
}



