#include "lexical_analyzer.h"
#include "parser_components.h"
#include "symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>

namespace Parser{
    void function_declaration_analyzer(){
        Lexical lexical = Lexical();
        lexical.next_token();
        // nível := “L” (marca ou novo galho)
        if(lexical.get_current_token().symbol == Symbols::SIDENTIFICADOR){
            // pesquisa_declfunc_tabela(token.lexema)
            // se não encontrou
            // então início
                // Insere_tabela(token.lexema,””,nível,rótulo)
                lexical.next_token();
                if(lexical.get_current_token().symbol == Symbols::SDOISPONTOS){
                    lexical.next_token();

                    if(lexical.get_current_token().symbol == Symbols::SINTEIRO || lexical.get_current_token().symbol == Symbols::SBOOLEANO){
                        // se (token.símbolo = Sinteger)
                        // então TABSIMB[pc].tipo:=
                        //     “função inteiro”
                        // senão TABSIMB[pc].tipo:=
                        //     “função booleana”
                        lexical.next_token();
                        if(lexical.get_current_token().symbol == Symbols::SPONTO_VIRGULA){
                            Parser::snippet_analyzer();
                        }

                    } else{
                        // erro
                        raiseError(Error::EXPECTED_BOOLEAN_OR_INT);
                    }
                } else{
                    // erro
                    raiseError(Error::EXPECTED_COLON);
                }
        } else{
            // erro
            raiseError(Error::EXPECTED_IDENTIFIER);
        }
        // DESEMPILHA OU VOLTA NÍVEL
    }
}