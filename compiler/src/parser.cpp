#include <iostream>
#include <fstream>
#include <filesystem>

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
#include "DVM.h"
#include "symbol_table.h"


void parser(char *file_path){
    Lexical lexical = Lexical();
    lexical.open_file(file_path);
    DVM dvm = DVM();
    Symbol_table symbol_table = Symbol_table();
    //Token* token;
    // rotulo := 1
    Label::setLabel(1);
    Address::setAddress(0);

    std::filesystem::path desktopPath = std::filesystem::current_path();
    std::string targetFolderName = "objs";
    std::filesystem::path targetFolderPath = desktopPath.parent_path() / targetFolderName;
    // std::filesystem::path outputPath = desktopPath / "virtual_machine";

    if (!std::filesystem::exists(targetFolderPath)) {
        std::filesystem::create_directory(targetFolderPath);
    }

    std::filesystem::path filePath = targetFolderPath / "byte_code.obj";

    if (std::filesystem::exists(filePath)) {
        std::ofstream clearFile(filePath, std::ios::out | std::ios::trunc);
        if (clearFile.is_open()) {
            clearFile.close();
        } else {
            std::cerr << "Error opening file for clearing: " << filePath << std::endl;
        }
    } 


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

    dvm.executeFromFile("byte_code.obj");
    lexical.close_file();
}


int main(int argc, char *argv[]) {
    Lexical lexical = Lexical();
    Expr_builder expr_builder = Expr_builder();

    bool is_file_provided = false;
    char* file_path;

    for(int i = 0 ; i < argc ; i++){
        std::string arg = argv[i];

        if(arg == "--dev"|| arg == "-D"){
            //Call tests functions from dev_env directory
            expression();
        }

        if((arg == "--file" || arg == "-f" ) && i+1 <= argc){
            is_file_provided = true;
            file_path = argv[i+1];
        }
    }

    if(is_file_provided)
        parser(file_path);
    else
        std::cout << "To run parser, a file must be provided with --file or -f." << std::endl;

    // for(Expr_token token : expr_builder.expr_array){
    //     std::cout << "lexem: " << token.lexem << std::endl;
    // }

    return 0;
}

