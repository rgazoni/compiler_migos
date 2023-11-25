#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

#include "Expr_token.h"
#include "semantic_analyzer.h"
#include "expression_builder.h"
#include "Token.h"
#include "symbols.h"

const char* symbolToString(Symbols symbol) {
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

// std::ostream& operator<<(std::ostream& os, const Symbols token) {
//     os << symbolToString(token);
//     return os;
// }

// Tabela de tipos
// unordered_map -> implementa uma hash table desorndenada - busca, inserçao e remoção = média de O(1)
std::unordered_map<std::string, Symbols> typesTable = {
    {"int", Symbols::SINTEIRO},
    {"bool", Symbols::SBOOLEANO},
    {"+", Symbols::SINTEIRO},
    {"-", Symbols::SINTEIRO},
    {"*", Symbols::SINTEIRO},
    {"=", Symbols::SINTEIRO},
    {"div", Symbols::SINTEIRO},
    {"!=", Symbols::SINTEIRO},
    {">", Symbols::SINTEIRO},
    {"<", Symbols::SINTEIRO},
    {"<=", Symbols::SINTEIRO},
    {">=", Symbols::SINTEIRO},
    {"e", Symbols::SBOOLEANO},
    {"ou", Symbols::SBOOLEANO},
    {"nao", Symbols::SBOOLEANO},
};

bool isOperator(const std::string& token) {
    return typesTable.find(token) != typesTable.end();
}

Symbols applyOperation(Symbols operando1, Symbols operando2, const std::string& operador) {
    if (operador == "+" || operador == "-" || operador == "*" || operador == "div") {
        if (operando1 == Symbols::SINTEIRO && operando2 == Symbols::SINTEIRO) {
            return Symbols::SINTEIRO;
        }
    } else if (operador == "=" || operador == "!=" || operador == "<" || operador == ">" || operador == "<=" || operador == ">=") {
        if (operando1 == Symbols::SINTEIRO && operando2 == Symbols::SINTEIRO) {
            return Symbols::SBOOLEANO;
        }
    } else if (operador == "e" || operador == "ou") {
        if (operando1 == Symbols::SBOOLEANO && operando2 == Symbols::SBOOLEANO) {
            return Symbols::SBOOLEANO;
        }
    } 
    return Symbols::SDESCONHECIDO;
}

bool isUnaryOperator(Symbols operador) {
    return operador == Symbols::SUNARIOARITMETICO || operador == Symbols::SUNARIOLOGICO;
}

Symbols applyUnaryOperation(Symbols operando, Symbols operador) {
    if (operador == Symbols::SUNARIOARITMETICO && operando == Symbols::SINTEIRO) {
        return Symbols::SINTEIRO;
    } else if (operador == Symbols::SUNARIOLOGICO && operando == Symbols::SBOOLEANO) {
        return Symbols::SBOOLEANO;
    }
    return Symbols::SDESCONHECIDO;
}

Symbols Semantic_analyzer::validateExpression(std::vector<Expr_token>& expression) {
    std::stack<Symbols> stack;

    for (const Expr_token& token : expression) {
        if (isOperator(token.lexem)) {
            if (isUnaryOperator(token.symbol)) { // Operador unário
                if (stack.empty()) {
                    std::cerr << "Erro semântico: Não há operandos para o operador '" << token.lexem << "'" << std::endl;
                    return Symbols::SDESCONHECIDO;
                }
                Symbols operando = stack.top();
                stack.pop();
                Symbols resultado = applyUnaryOperation(operando, token.symbol);
                if (resultado == Symbols::SDESCONHECIDO) {
                    std::cerr << "Erro semântico: Tipo inválido para o operador unário '" << token.lexem << "'" << std::endl;
                    return Symbols::SDESCONHECIDO;
                }
                stack.push(resultado);
            } else {
                if (stack.size() < 2) {
                    std::cerr << "Erro semântico: Não há operandos suficientes para o operador '" << token.lexem << "'" << std::endl;
                    return Symbols::SDESCONHECIDO;
                }
                Symbols operando2 = stack.top();
                stack.pop();
                Symbols operando1 = stack.top();
                stack.pop();
                Symbols resultado = applyOperation(operando1, operando2, token.lexem);
                if (resultado == Symbols::SDESCONHECIDO) {
                    std::cerr << "Erro semântico: Tipos inválidos para o operador '" << token.lexem << "'" << std::endl;
                    return Symbols::SDESCONHECIDO;
                }
                stack.push(resultado);
            }
        } else {
            stack.push(token.symbol);
        }
    }


    if (stack.size() == 1) {
        return stack.top();
    } else {
        std::cerr << "Erro semântico: Expressão malformada" << std::endl;
        return Symbols::SDESCONHECIDO;
    }
}