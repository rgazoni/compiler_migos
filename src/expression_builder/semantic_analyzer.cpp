#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

#include "Expr_token.h"
#include "semantic_analyzer.h"
#include "expression_builder.h"

// Tabela de tipos
// unordered_map -> implementa uma hash table desorndenada - busca, inserçao e remoção = média de O(1)
std::unordered_map<std::string, Type> typesTable = {
    {"int", Type::Int},
    {"bool", Type::Bool},
    {"+", Type::Int},
    {"-", Type::Int},
    {"*", Type::Int},
    {"=", Type::Int},
    {"+_un", Type::Int},
    {"-_un", Type::Int},
    {"div", Type::Int},
    {"!=", Type::Int},
    {">", Type::Int},
    {"<", Type::Int},
    {"<=", Type::Int},
    {">=", Type::Int},
    {"e", Type::Bool},
    {"ou", Type::Bool},
    {"nao", Type::Bool},
    {"nao_un", Type::Bool},
};

bool isOperator(const std::string& token) {
    return typesTable.find(token) != typesTable.end();
}

Type applyOperation(Type operando1, Type operando2, const std::string& operador) {
    if (operador == "+" || operador == "-" || operador == "*" || operador == "div") {
        if (operando1 == Type::Int && operando2 == Type::Int) {
            return Type::Int;
        }
    } else if (operador == "=" || operador == "!=" || operador == "<" || operador == ">" || operador == "<=" || operador == ">=") {
        if (operando1 == Type::Int && operando2 == Type::Int) {
            return Type::Bool;
        }
    } else if (operador == "e" || operador == "ou") {
        if (operando1 == Type::Bool && operando2 == Type::Bool) {
            return Type::Bool;
        }
    } 
    return Type::Unknown;
}

bool isUnaryOperator(Type operador) {
    return operador == Type::Arit_unary || operador == Type::Logical_unary;
}

Type applyUnaryOperation(Type operando, Type operador) {
    if (operador == Type::Arit_unary && operando == Type::Int) {
        return Type::Int;
    } else if (operador == Type::Logical_unary && operando == Type::Bool) {
        return Type::Bool;
    }
    return Type::Unknown;
}

Type Semantic_analyzer::validateExpression(std::vector<Expr_token>& expression) {
    std::stack<Type> stack;

    for (const Expr_token& token : expression) {
        if (isOperator(token.lexem)) {
            if (isUnaryOperator(token.type)) { // Operador unário
                if (stack.empty()) {
                    std::cerr << "Erro semântico: Não há operandos para o operador '" << token.lexem << "'" << std::endl;
                    return Type::Unknown;
                }
                Type operando = stack.top();
                stack.pop();
                Type resultado = applyUnaryOperation(operando, token.type);
                if (resultado == Type::Unknown) {
                    std::cerr << "Erro semântico: Tipo inválido para o operador unário '" << token.lexem << "'" << std::endl;
                    return Type::Unknown;
                }
                stack.push(resultado);
            } else {
                if (stack.size() < 2) {
                    std::cerr << "Erro semântico: Não há operandos suficientes para o operador '" << token.lexem << "'" << std::endl;
                    return Type::Unknown;
                }
                Type operando2 = stack.top();
                stack.pop();
                Type operando1 = stack.top();
                stack.pop();
                Type resultado = applyOperation(operando1, operando2, token.lexem);
                if (resultado == Type::Unknown) {
                    std::cerr << "Erro semântico: Tipos inválidos para o operador '" << token.lexem << "'" << std::endl;
                    return Type::Unknown;
                }
                stack.push(resultado);
            }
        } else {
            stack.push(token.type);
        }
    }

    // Expr_builder().flush_expression();

    if (stack.size() == 1) {
        return stack.top();
    } else {
        std::cerr << "Erro semântico: Expressão malformada" << std::endl;
        return Type::Unknown;
    }
}