#include <iostream>
#include <algorithm>
#include <locale>
#include <functional>
#include <string>
#include <algorithm> 
#include <stack>

#include "expression_builder.h"
#include "semantic_analyzer.h"
#include "generate.h"
#include "label.h"

using namespace std;

void print_type(Type type){
    if(type == Type::Int)
        cout << "type: inteiro" << endl;  
    if(type == Type::Bool)
        cout << "type: booleano" << endl;  
}

enum Precedence {
    UNARY = 6,
    MULTIPLICATIVE = 5,
    ADDITIVE = 4,
    RELATIONAL = 3,
    NOT = 2,
    AND = 1,
    OR = 0,
    DEFAULT_PRECEDENCE = -1  // Valor padrão para tratamento de erros
};

std::vector<string> Expr_builder::integer_variables = {};
std::vector<string> Expr_builder::boolean_variables = {};
std::vector<string> Expr_builder::any_variables = {};
std::vector<Expr_token> Expr_builder::expr_array = {};


void Expr_builder::add_to_array(Expr_token token){
    expr_array.push_back(token);
}

void Expr_builder::flush_expression(){
    Expr_builder::expr_array = {};
}

bool isOperator(string token) {
    std::vector<std::string> operators = {
        "+", "-", "*", "div",  // Arithmetic operators
        "=", "!=", "<", ">", "<=", ">=",  // Comparison operators
        "e", "ou", "nao"  // Logical operators
        // ":=" // Assignment operators
        // "verdadeiro", "falso", // Boolean operators
    };

    // Check if the token is in the list of operators
    for (std::string op : operators) {
        if (token == op) {
            return true;
        }
    }

    return false;
}

bool isOperand (string lexem) {
    if(lexem == "div" || lexem == "e" || lexem == "ou" || lexem == "nao"){
        return false;
    }

    if(lexem == "verdadeiro" || lexem == "falso"){
        return true;
    }

    if ((isalpha(lexem[0]) || isdigit(lexem[0]))) {
        return true;
    }   

    return false;
}

bool Expr_builder::isUnary(int i){
    if(i == 0 || isOperator(expr_array[i-1].lexem) || expr_array[i-1].lexem == "("){
        // expr_array[i].lexem = expr_array[i].lexem + "_un";
        return true;
    }

    return false;
}

int Expr_builder::precedence(string lexem, int position) {
    if (lexem == "*" || lexem == "div") {
        return Precedence::MULTIPLICATIVE;
    } else if (lexem == "+" || lexem == "-") {
        if(isUnary(position)){
            expr_array[position].type = Type::Arit_unary;
            return Precedence::UNARY;
        }
        return Precedence::ADDITIVE;
    } else if (lexem == "=" || lexem == "<=" || lexem == ">=" || lexem == "<" || lexem == ">" || lexem == "!=") {
        return Precedence::RELATIONAL;
    } else if (lexem == "nao") {
        if(isUnary(position)){
            expr_array[position].type = Type::Logical_unary;
            return Precedence::UNARY;
        }
        return Precedence::NOT;
    } else if (lexem == "e") {
        return Precedence::AND;
    } else if (lexem == "ou") {
        return Precedence::OR;
    }

    return Precedence::DEFAULT_PRECEDENCE;
}

Type Expr_builder::infix_to_postfix() {
    std::stack<Expr_token> stack;
    std::vector<Expr_token> postfix;

    for (int i = 0; i < expr_array.size(); i++) { 
        if (isOperand(expr_array[i].lexem)) {
            postfix.push_back(expr_array[i]);
        } else if (expr_array[i].lexem == "(") {
            stack.push(expr_array[i]);
        } else if (expr_array[i].lexem == ")") {
            while (!stack.empty() && stack.top().lexem != "(") {
                postfix.push_back(stack.top());
                stack.pop();
            }
            if (!stack.empty() && stack.top().lexem == "(") {
                stack.pop(); // Pop the opening parenthesis
            }
        } else if (isOperator(expr_array[i].lexem)) {

            int tokenPrecedence = precedence(expr_array[i].lexem, i);

            while (!stack.empty() && (tokenPrecedence < precedence(stack.top().lexem, i) ||
                    (tokenPrecedence == precedence(stack.top().lexem, i) && tokenPrecedence != Precedence::UNARY))) {
                postfix.push_back(stack.top());
                stack.pop();
            }
            stack.push(expr_array[i]);
        }
    }

    while (!stack.empty()) {
        postfix.push_back(stack.top());
        stack.pop();
    }

    expr_array = postfix;

    // for(Expr_token element : expr_array){
    //     std::cout << "lexem: " << element.lexem <<  " -- ";
    //     print_type(element.type);
    // }

    Type resultado = Semantic_analyzer().validateExpression(expr_array);

    string command, attribute1 = "";

    if (resultado == Type::Int || resultado == Type::Bool){ 
        for(Expr_token token : expr_array){
            if (isOperator(token.lexem)){
                command = get_lpd_symbols(token.lexem);
                generate("", command, "", "");

            } else if(isdigit(token.lexem[0])){
                command = "LDC";
                attribute1 = token.lexem;
                generate("", command, attribute1, "");

            } else if(token.lexem == "verdadeiro"){
                command = "LDC";
                attribute1 = "1";
                generate("", command, attribute1, "");

            } else if(token.lexem == "falso"){
                command = "LDC";
                attribute1 = "0";
                generate("", command, attribute1, "");

            } else {
                command = "LDV";
                // attribute1 = to_string(token.address);
                generate("", command, token.lexem, "");
            }
        }
    }

    postfix.clear();
    Expr_builder().flush_expression();

    // if(expr_array.empty()){
    //     std::cout << "vaziuu" << std::endl;
    // }

    // std::cout << std::endl;

    return resultado;
}

