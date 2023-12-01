#include <iostream>
#include "expression_builder.h"
#include "../parser_components/parser_components.h"
#include "error/Errors.h"
#include "lexical/lexical_analyzer.h"
#include "symbols.h"
#include "semantic_analyzer.h"
#include "expression_builder.h"
#include "dev_env/tests.h"
#include "label.h"
#include "generate.h"
#include "address.h"
// #include "DVM.h"
#include "symbol_table.h"
#include "parser.h"

void parser(const char *file_path){
    Lexical lexical = Lexical();
    lexical.open_file(file_path);
    // DVM dvm = DVM();
    Symbol_table symbol_table = Symbol_table();
    //Token* token;
    // rotulo := 1
    Label::setLabel(1);
    Address::setAddress(0);
    lexical.next_token();

    if (lexical.get_current_token().symbol == Symbols::SPROGRAMA) {
        generate("", "START", "", "");
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
                    // std::cout << lexical.get_current_token().lexem << std::endl;
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
    // symbol_table.print_table();

    generate("", "DALLOC", to_string(stoi(Address::getAddress()) - Address::getVarCount()), to_string(Address::getVarCount()));
    generate("", "HLT", "", "");

    // dvm.executeFromFile("byte_code.obj");
    lexical.close_file();
}

