#include "symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "lexical_analyzer.h"
#include "parser_components.h"

namespace Parser {
    void factor_analyzer(){
        Lexical lexical = Lexical();

        if(lexical.get_current_token().symbol == Symbols::SIDENTIFICADOR){
            // Se pesquisa_tabela(token.lexema,nível,ind)
            // Então Se (TabSimb[ind].tipo = “função inteiro”) ou 
            //     (TabSimb[ind].tipo = “função booleano”)
            // Então Analisa_chamada_função 
            //     Senão Léxico(token)
            // Senão ERRO
            Parser::function_caller_analyzer();
        }else if(lexical.get_current_token().symbol == Symbols::SNUMERO){
            lexical.next_token();
        }else if(lexical.get_current_token().symbol == Symbols::SNAO){
            lexical.next_token();
            Parser::factor_analyzer();

        }else if(lexical.get_current_token().symbol == Symbols::SABRE_PARENTESES){
            lexical.next_token();
            Parser::expression_analyzer();
            if(lexical.get_current_token().symbol == Symbols::SFECHA_PARENTESES){
                lexical.next_token();

            }else{
                raiseError(Error::EXPECTED_CLOSE_PARENTHESIS);
            }
        } else if(lexical.get_current_token().lexem == "true" || lexical.get_current_token().lexem == "false"){
            //lexic(token);
            lexical.next_token();
            
        }else{
            raiseError(Error::EXPECTED_ELEMENT);
        }
    }
}