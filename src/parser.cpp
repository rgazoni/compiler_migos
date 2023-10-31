#include <iostream>

#include "../parser_components/parser_components.h"
#include "error/Errors.h"
#include "lexical/lexical_analyzer.h"
#include "symbols.h"
#include "symbol_table.h"

int main(int argc, char *argv[]) {
    Lexical lexical = Lexical();
    Record record;
    Symbol_table symbol_table = Symbol_table();
    lexical.open_file(argv);
    //Token* token;
    // rotulo := 1
    lexical.next_token();

    ///////////
    lexical.next_token();
    lexical.next_token();
    std::cout << lexical.get_current_token().symbol << std::endl;
    std::cout << lexical.get_current_token().lexem << std::endl;

    while(lexical.get_current_token().symbol != Symbols::SPONTO){
        record.setLexem(lexical.get_current_token().lexem);
        record.setSymbol(lexical.get_current_token().symbol);
        record.setType("asdad");
        record.setAddress(0);
        symbol_table.insert_record_variable(&record);
        lexical.next_token();
    }
    symbol_table.print_table();
    //////////////////////////////////
    
    // if (lexical.get_current_token().symbol == Symbols::SPROGRAMA) {
    //     lexical.next_token();
        
    //     if (lexical.get_current_token().symbol == Symbols::SIDENTIFICADOR) {            
    //         // insere_tabela(token->lexema,"nomedeprograma", "", "")
    //         lexical.next_token();
    //         if (lexical.get_current_token().symbol == Symbols::SPONTO_VIRGULA) {
    //             // analisa_bloco
    //             Parser::snippet_analyzer();
    //             // lexical.next_token();

    //             if (lexical.get_current_token().symbol == Symbols::SPONTO) {
    //                 lexical.next_token();
    //                 std::cout << lexical.get_current_token().lexem << std::endl;
    //                 if (lexical.get_current_token().symbol !=
    //                     Symbols::END_OF_FILE)
    //                     raiseError(Error::EXPECTED_EOF);
    //             } else {
    //                 raiseError(Error::EXPECTED_DOT);
    //             }
    //         } else {
    //             raiseError(Error::EXPECTED_SEMICOLON);
    //         }
    //     } else {
    //         raiseError(Error::EXPECTED_IDENTIFIER);
    //     }
    // } else {
    //     raiseError(Error::EXPECTED_RESERVED_WORD_PROGRAMA);
    // }

    lexical.close_file();

    return 0;
}
