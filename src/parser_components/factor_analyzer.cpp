#include "symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "lexical_analyzer.h"
#include "expression_builder.h"
#include "parser_components.h"
#include <algorithm>
#include <vector>

using namespace std;

namespace Parser {
    void factor_analyzer(){
        Lexical lexical = Lexical();
        Expr_builder expr_builder = Expr_builder();

        if(lexical.get_current_token().symbol == Symbols::SIDENTIFICADOR){
            // Se pesquisa_tabela(token.lexema,nível,ind)
            // Então Se (TabSimb[ind].tipo = “função inteiro”) ou 
            //     (TabSimb[ind].tipo = “função booleano”)
            // Então Analisa_chamada_função 
            //     Senão Léxico(token)
            // Senão ERRO

            //não trata se é variavel ou função - n~~ao há diferença
            // if(lexical.get_current_token().symbol == Symbols::SINTEIRO)
            //     expr_builder.add_to_array(Expr_token(lexical.get_current_token().lexem, Type::Int));
            // else if(lexical.get_current_token().symbol == Symbols::SBOOLEANO)
            //     expr_builder.add_to_array(Expr_token(lexical.get_current_token().lexem, Type::Bool));

            //SO POR VIA DE TESTES
            // if(find(expr_builder.integer_variables.begin(), expr_builder.integer_variables.end(), lexical.get_current_token().lexem) != expr_builder.integer_variables.end()){
            //     expr_builder.add_to_array(Expr_token(lexical.get_current_token().lexem, "SINTEIRO"));
            // } else if(find(expr_builder.boolean_variables.begin(), expr_builder.boolean_variables.end(), lexical.get_current_token().lexem) != expr_builder.boolean_variables.end()){
            //     expr_builder.add_to_array(Expr_token(lexical.get_current_token().lexem, "SBOOLEANO"));
            // }

            expr_builder.add_to_array(lexical.get_current_token());
            Parser::function_caller_analyzer();
        }else if(lexical.get_current_token().symbol == Symbols::SNUMERO){
            expr_builder.add_to_array(lexical.get_current_token());
            lexical.next_token();

        }else if(lexical.get_current_token().symbol == Symbols::SNAO){
            expr_builder.add_to_array(lexical.get_current_token());
            lexical.next_token();
            Parser::factor_analyzer();

        }else if(lexical.get_current_token().symbol == Symbols::SABRE_PARENTESES){
            expr_builder.add_to_array(lexical.get_current_token());
            lexical.next_token();
            Parser::expression_analyzer();
            if(lexical.get_current_token().symbol == Symbols::SFECHA_PARENTESES){
                expr_builder.add_to_array(lexical.get_current_token());
                lexical.next_token();

            }else{
                raiseError(Error::EXPECTED_CLOSE_PARENTHESIS);
            }
        } else if(lexical.get_current_token().lexem == "verdadeiro" || lexical.get_current_token().lexem == "falso"){
            // we don't know how to treat "true" or "false" token 
            expr_builder.add_to_array(lexical.get_current_token());
            lexical.next_token();
            
        }else{
            raiseError(Error::EXPECTED_ELEMENT);
        }
    }
}