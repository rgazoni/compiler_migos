#include "../token/symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "lexical_analyzer.h"
#include "../parser_components/parser_components.h"

namespace Parser {
    void command_analyzer(){
        Lexical lexical = Lexical();

        if (lexical.get_current_token().symbol == Symbols::SINICIO) {                        
            lexical.next_token();
            
            Parser::simple_command_analyzer(); 
            

            while (lexical.get_current_token().symbol != Symbols::SFIM) {

                if (lexical.get_current_token().symbol == Symbols::SPONTO_VIRGULA) {
                    lexical.next_token();
                    
                    if (lexical.get_current_token().symbol != Symbols::SFIM) {
                        Parser::simple_command_analyzer();
                    }
                } else {
                    raiseError(Error::EXPECTED_SEMICOLON);
                }
            }
            lexical.next_token();
        } else {
            std::cout << lexical.get_current_token().symbol << std::endl;
            std::cout << lexical.get_current_token().lexem << std::endl;
           raiseError(Error::EXPECTED_IDENTIFIER);
        } 
    }
} 