#include "../symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "lexical_analyser.h"
#include "../parser_components/general_parser.h"

namespace Parser {
    void command_analyzer(){
        Lexical lexical = Lexical();

        if (lexical.get_current_token().symbol == Symbols::SINICIO) {                        
            lexical.next_token();
            //Parser::simple_command_analyzer(); 

            while (lexical.get_current_token().symbol != Symbols::SFIM) {

                if (lexical.get_current_token().symbol == Symbols::SPONTO_VIRGULA) {
                    lexical.next_token();
                    
                    if (lexical.get_current_token().symbol != Symbols::SFIM) {
                        //Parser::simple_command_analyzer();
                    }
                } else {
                    raiseError(Error::EXPECTED_SEMICOLON);
                }
            }
            lexical.next_token();
        } else {
           raiseError(Error::EXPECTED_IDENTIFIER);
        } 
    }
} 