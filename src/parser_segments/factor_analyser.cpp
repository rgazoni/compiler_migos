#include "symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "lexical_analyser.h"
#include "general_parser.h"

namespace Parser {
    void factor_analyser(){
        Token* token;
        if(token->symbol == Symbols::SIDENTIFICADOR){
            //if(pesquisa_tabela(token->lexem, nivel, ind)){
            //     if(TabSimb[ind].->tipo == "funcao inteiro" || TabSimb[ind].->tipo == "funcao booleano")
            //         Analisa_chamada_funcao
            //     else{
            //         Lexic(token);
            //      }
            //} else{
            //    error
            //}
        }else if(token->symbol == Symbols::SNUMERO){
                token = Lexical::get_token();
                //lexic(token)
        }else if(token->symbol == Symbols::SNAO){
            //lexic(token)
            token = Lexical::get_token();
            factor_analyser();
        }else if(token->symbol == Symbols::SABRE_PARENTESES){
            //lexic(token);
            token = Lexical::get_token();

            //expression_analyser
            if(token->symbol == Symbols::SFECHA_PARENTESES){
                token = Lexical::get_token();
                //lexic(token);
            }else{
                raiseError(Error::EXPECTED_CLOSE_PARENTHESIS);
            }
        } else if(token->lexem == "true" || token->lexem == "false"){
            //lexic(token);
            token = Lexical::get_token();
        }else{
            raiseError(Error::EXPECTED_LEXEM);
        }
    }
}