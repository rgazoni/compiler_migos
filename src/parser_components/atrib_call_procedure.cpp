#include "../token/symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>
#include "lexical_analyzer.h"
#include "../parser_components/parser_components.h"
#include "expression_builder.h"
#include "generate.h"
#include "symbol_table.h"

namespace Parser {

    string symbolToString(Symbols symbol) {
    switch (symbol) {
        case Symbols::SPROGRAMA: return "PROGRAMA";
        case Symbols::SSE: return "SE";
        case Symbols::SENTAO: return "ENTAO";
        case Symbols::SSENAO: return "SENAO";
        case Symbols::SENQUANTO: return "ENQUANTO";
        case Symbols::SFACA: return "FACA";
        case Symbols::SINICIO: return "INICIO";
        case Symbols::SFIM: return "FIM";
        case Symbols::SESCREVA: return "ESCREVA";
        case Symbols::SLEIA: return "LEIA";
        case Symbols::SVAR: return "VAR";
        case Symbols::SINTEIRO: return "INTEIRO";
        case Symbols::SBOOLEANO: return "BOOLEANO";
        case Symbols::SVERDADEIRO: return "VERDADEIRO";
        case Symbols::SFALSO: return "FALSO";
        case Symbols::SPROCEDIMENTO: return "PROCEDIMENTO";
        case Symbols::SFUNCAO: return "FUNCAO";
        case Symbols::SDIV: return "DIV";
        case Symbols::SE: return "E";
        case Symbols::SOU: return "OU";
        case Symbols::SNAO: return "NAO";
        case Symbols::SIDENTIFICADOR: return "IDENTIFICADOR";
        case Symbols::SNUMERO: return "NUMERO";
        case Symbols::SMAIS: return "MAIS";
        case Symbols::SMENOS: return "MENOS";
        case Symbols::SMULT: return "MULT";
        case Symbols::SUNARIOARITMETICO: return "UNARIOARITMETICO";
        case Symbols::SUNARIOLOGICO: return "UNARIOLOGICO";
        case Symbols::SDESCONHECIDO: return "DESCONHECIDO";
        case Symbols::SMAIORIG: return "MAIORIG";
        case Symbols::SMAIOR: return "MAIOR";
        case Symbols::SMENORIG: return "MENORIG";
        case Symbols::SMENOR: return "MENOR";
        case Symbols::SDIF: return "DIF";
        case Symbols::SIG: return "IG";
        case Symbols::SPONTO_VIRGULA: return "PONTO_VIRGULA";
        case Symbols::SVIRGULA: return "VIRGULA";
        case Symbols::SABRE_PARENTESES: return "ABRE_PARENTESES";
        case Symbols::SFECHA_PARENTESES: return "FECHA_PARENTESES";
        case Symbols::SPONTO: return "PONTO";
        case Symbols::SATRIBUICAO: return "ATRIBUICAO";
        case Symbols::SDOISPONTOS: return "DOISPONTOS";
        case Symbols::SERRO: return "ERRO";
        case Symbols::EMPTY: return "EMPTY";
        case Symbols::END_OF_FILE: return "END_OF_FILE";
        default: return "UNKNOWN_SYMBOL";
    }
}

    void atribution_and_call_procedure(){
        Lexical lexical = Lexical();
        Expr_builder expr_builder = Expr_builder();
        Token token = lexical.get_current_token();
        Symbol_table symbol_table;

        // cout << "ant3es: " << lexical.get_current_token().lexem << " - symbol: " << symbolToString(lexical.get_current_token().symbol) << endl;
        lexical.next_token();
        // cout << "esse pokemon: " << lexical.get_current_token().lexem << " - symbol: " << symbolToString(lexical.get_current_token().symbol) << endl;

        if (lexical.get_current_token().symbol == Symbols::SATRIBUICAO) {
            //Analisa_atribuicao();
            //buscar na tabela de simbolos
            Parser::assignment_analyzer();
            expr_builder.infix_to_postfix();
            // symbol_table.print_table();

            //buscar na tabela de simbolos para colocar o endereço no gera
            generate("", "STR", std::to_string(symbol_table.get_variable_address(token.lexem)), "");
        } else {
           //Chamada_procedimento();
           Parser::procedure_caller_analyzer();
        }
    }
}
