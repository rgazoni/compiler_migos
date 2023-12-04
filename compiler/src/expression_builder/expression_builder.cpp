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
#include "lexical_analyzer.h"
#include "Expr_token.h"
#include "Token.h"
#include "symbol_table.h"

using namespace std;

// void print_type(Type type){
//     if(type == Type::Int)
//         cout << "type: inteiro" << endl;  
//     if(type == Type::Bool)
//         cout << "type: booleano" << endl;  
// }

// string symbolToString(Symbols symbol) {
//     switch (symbol) {
//         case Symbols::SPROGRAMA: return "PROGRAMA";
//         case Symbols::SSE: return "SE";
//         case Symbols::SENTAO: return "ENTAO";
//         case Symbols::SSENAO: return "SENAO";
//         case Symbols::SENQUANTO: return "ENQUANTO";
//         case Symbols::SFACA: return "FACA";
//         case Symbols::SINICIO: return "INICIO";
//         case Symbols::SFIM: return "FIM";
//         case Symbols::SESCREVA: return "ESCREVA";
//         case Symbols::SLEIA: return "LEIA";
//         case Symbols::SVAR: return "VAR";
//         case Symbols::SINTEIRO: return "INTEIRO";
//         case Symbols::SBOOLEANO: return "BOOLEANO";
//         case Symbols::SVERDADEIRO: return "VERDADEIRO";
//         case Symbols::SFALSO: return "FALSO";
//         case Symbols::SPROCEDIMENTO: return "PROCEDIMENTO";
//         case Symbols::SFUNCAO: return "FUNCAO";
//         case Symbols::SDIV: return "DIV";
//         case Symbols::SE: return "E";
//         case Symbols::SOU: return "OU";
//         case Symbols::SNAO: return "NAO";
//         case Symbols::SIDENTIFICADOR: return "IDENTIFICADOR";
//         case Symbols::SNUMERO: return "NUMERO";
//         case Symbols::SMAIS: return "MAIS";
//         case Symbols::SMENOS: return "MENOS";
//         case Symbols::SMULT: return "MULT";
//         case Symbols::SUNARIOARITMETICO: return "UNARIOARITMETICO";
//         case Symbols::SUNARIOLOGICO: return "UNARIOLOGICO";
//         case Symbols::SDESCONHECIDO: return "DESCONHECIDO";
//         case Symbols::SMAIORIG: return "MAIORIG";
//         case Symbols::SMAIOR: return "MAIOR";
//         case Symbols::SMENORIG: return "MENORIG";
//         case Symbols::SMENOR: return "MENOR";
//         case Symbols::SDIF: return "DIF";
//         case Symbols::SIG: return "IG";
//         case Symbols::SPONTO_VIRGULA: return "PONTO_VIRGULA";
//         case Symbols::SVIRGULA: return "VIRGULA";
//         case Symbols::SABRE_PARENTESES: return "ABRE_PARENTESES";
//         case Symbols::SFECHA_PARENTESES: return "FECHA_PARENTESES";
//         case Symbols::SPONTO: return "PONTO";
//         case Symbols::SATRIBUICAO: return "ATRIBUICAO";
//         case Symbols::SDOISPONTOS: return "DOISPONTOS";
//         case Symbols::SERRO: return "ERRO";
//         case Symbols::EMPTY: return "EMPTY";
//         case Symbols::END_OF_FILE: return "END_OF_FILE";
//         default: return "UNKNOWN_SYMBOL";
//     }
// }


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

// std::vector<string> Expr_builder::integer_variables = {};
// std::vector<string> Expr_builder::boolean_variables = {};
// std::vector<string> Expr_builder::any_variables = {};
std::vector<Expr_token> Expr_builder::expr_array = {};

void Expr_builder::add_to_array(Token token){
    if(token.symbol == Symbols::SE || token.symbol == Symbols::SOU){
        Expr_token expr_token(token.lexem, Symbols::SBOOLEANO, 0);
        expr_array.push_back(expr_token);

    } else if(token.symbol == Symbols::SMAIS || token.symbol == Symbols::SMENOS || token.symbol == Symbols::SDIV || token.symbol == Symbols::SMULT){
        Expr_token expr_token(token.lexem, Symbols::SINTEIRO, 0);
        expr_array.push_back(expr_token);
    }    
    
}

void Expr_builder::add_to_array(Token token, Symbols symbol){
    if(token.symbol == Symbols::SE || token.symbol == Symbols::SOU){
        Expr_token expr_token(token.lexem, Symbols::SBOOLEANO, 0);
        expr_array.push_back(expr_token);

    } else if(token.symbol == Symbols::SMAIS || token.symbol == Symbols::SMENOS || token.symbol == Symbols::SDIV || token.symbol == Symbols::SMULT){
        Expr_token expr_token(token.lexem, Symbols::SINTEIRO, 0);
        expr_array.push_back(expr_token);
    }

    Expr_token expr_token(token.lexem, symbol, 0);
    expr_array.push_back(expr_token);
    
    
}

void Expr_builder::add_to_array(Token token, Symbols symbol, int address){
    to_string(address);
    // cout << "address: " << address << endl;
    
    Expr_token expr_token(token.lexem, symbol, address);
    expr_array.push_back(expr_token);
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
            expr_array[position].symbol = Symbols::SUNARIOARITMETICO;
            return Precedence::UNARY;
        }
        return Precedence::ADDITIVE;
    } else if (lexem == "=" || lexem == "<=" || lexem == ">=" || lexem == "<" || lexem == ">" || lexem == "!=") {
        return Precedence::RELATIONAL;
    } else if (lexem == "nao") {
        if(isUnary(position)){
            expr_array[position].symbol = Symbols::SUNARIOLOGICO;
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

Symbols Expr_builder::infix_to_postfix() {
    std::stack<Expr_token> stack;
    std::vector<Expr_token> postfix;
    Symbol_table symbol_table;

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
    //     // std::cout << "lexem: " << element.lexem <<  " - " << "symbol: " <<  symbolToString(element.symbol);
    //     cout << endl;
    //     // print_type(element.type);
    // }

    // cout << endl;

    Symbols resultado = Semantic_analyzer().validateExpression(expr_array);

    string command, attribute1 = "";

    if (resultado == Symbols::SINTEIRO || resultado == Symbols::SBOOLEANO){ 
        for(Expr_token token : expr_array){
            if (isOperator(token.lexem)){
                if (token.symbol == Symbols::SUNARIOARITMETICO && token.lexem == "-") {
                    command = "INV";
                    generate("", command, "", "");
                } else if (token.symbol == Symbols::SUNARIOARITMETICO && token.lexem == "+") {

                } else {
                    command = get_lpd_symbols(token.lexem);
                    generate("", command, "", "");
                }
                
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

            } else if(token.address == 0) {
                int label = symbol_table.get_function_label(token.lexem);
                generate("", "CALL", to_string(label), "");
                command = "LDV";
                generate("", command, to_string(token.address), "");
            } else {
                command = "LDV";
                generate("", command, to_string(token.address), "");
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

