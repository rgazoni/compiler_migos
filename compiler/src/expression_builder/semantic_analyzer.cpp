#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

#include "Expr_token.h"
#include "semantic_analyzer.h"
#include "expression_builder.h"
#include "Token.h"
#include "symbols.h"

// const char* symbolToString(Symbols symbol) {
//     switch (symbol) {
//         case Symbols::SPROGRAMA: return "SPROGRAMA";
//         case Symbols::SSE: return "SSE";
//         case Symbols::SENTAO: return "SENTAO";
//         case Symbols::SSENAO: return "SSENAO";
//         case Symbols::SENQUANTO: return "SENQUANTO";
//         case Symbols::SFACA: return "SFACA";
//         case Symbols::SINICIO: return "SINICIO";
//         case Symbols::SFIM: return "SFIM";
//         case Symbols::SESCREVA: return "SESCREVA";
//         case Symbols::SLEIA: return "SLEIA";
//         case Symbols::SVAR: return "SVAR";
//         case Symbols::SINTEIRO: return "SINTEIRO";
//         case Symbols::SBOOLEANO: return "SBOOLEANO";
//         case Symbols::SVERDADEIRO: return "SVERDADEIRO";
//         case Symbols::SFALSO: return "SFALSO";
//         case Symbols::SPROCEDIMENTO: return "SPROCEDIMENTO";
//         case Symbols::SFUNCAO: return "SFUNCAO";
//         case Symbols::SDIV: return "SDIV";
//         case Symbols::SE: return "SE";
//         case Symbols::SOU: return "SOU";
//         case Symbols::SNAO: return "SNAO";
//         case Symbols::SIDENTIFICADOR: return "SIDENTIFICADOR";
//         case Symbols::SNUMERO: return "SNUMERO";
//         case Symbols::SMAIS: return "SMAIS";
//         case Symbols::SMENOS: return "SMENOS";
//         case Symbols::SMULT: return "SMULT";
//         case Symbols::SUNARIOARITMETICO: return "SUNARIOARITMETICO";
//         case Symbols::SUNARIOLOGICO: return "SUNARIOLOGICO";
//         case Symbols::SDESCONHECIDO: return "SDESCONHECIDO";
//         case Symbols::SMAIORIG: return "SMAIORIG";
//         case Symbols::SMAIOR: return "SMAIOR";
//         case Symbols::SMENORIG: return "SMENORIG";
//         case Symbols::SMENOR: return "SMENOR";
//         case Symbols::SDIF: return "SDIF";
//         case Symbols::SIG: return "IG";
//         case Symbols::SPONTO_VIRGULA: return "SPONTO_VIRGULA";
//         case Symbols::SVIRGULA: return "SVIRGULA";
//         case Symbols::SABRE_PARENTESES: return "SABRE_PARENTESES";
//         case Symbols::SFECHA_PARENTESES: return "SFECHA_PARENTESES";
//         case Symbols::SPONTO: return "PSONTO";
//         case Symbols::SATRIBUICAO: return "SATRIBUICAO";
//         case Symbols::SDOISPONTOS: return "SDOISPONTOS";
//         case Symbols::SERRO: return "SERRO";
//         case Symbols::EMPTY: return "SEMPTY";
//         case Symbols::END_OF_FILE: return "SEND_OF_FILE";
//         default: return "UNKNOWN_SYMBOL";
//     }
// }

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