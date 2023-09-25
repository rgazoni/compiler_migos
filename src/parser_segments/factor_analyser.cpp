#include "symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>

int factor_analyser(){
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
            //lexic(token)
    }else if(token->symbol == Symbols::SNAO){
        //lexic(token)
        factor_analyser();
    }else if(token->symbol == Symbols::SABRE_PARENTESES){
        //lexic(token);
        //expression_analyser
        if(token->symbol == Symbols::SFECHA_PARENTESES){
            //lexic(token);
        }else{
            raiseError(Error::PARENTHESIS_DOES_NOT_CLOSE);
        }
    } else if(token->lexem == true || token->lexem == false){
        //lexic(token);
    }else{
        raiseError(Error::INCORRECT_LEXEM);
    }
}