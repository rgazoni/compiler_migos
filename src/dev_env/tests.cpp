#include <iostream>
#include <typeinfo>
#include "expression_builder.h"
#include "error/Errors.h"
#include "lexical/lexical_analyzer.h"
#include "symbols.h"
#include "semantic_analyzer.h"
#include "tests.h"
#include "generate.h"

// std::string enum_to_string(Type token){
//     switch(token){
//         case Type::Bool: return "bool";
//         case Type::Int: return "int";
//         case Type::Arit_unary: return "unary";
//         case Type::Logical_unary: return "l_unary";
//         default: return "Unknown";
//     }
// }

void expression(){
    // Expr_builder expr_builder = Expr_builder();
    // std::vector<Expr_token> array;
    // Type resultado;

    // // // Token* token;
    // expr_builder.add_to_array(Expr_token("(", Type::Unknown));
    // expr_builder.add_to_array(Expr_token("xx", Type::Int));
    // expr_builder.add_to_array(Expr_token("+", Type::Int));
    // expr_builder.add_to_array(Expr_token("7", Type::Int));
    // expr_builder.add_to_array(Expr_token("*", Type::Int));
    // expr_builder.add_to_array(Expr_token("5", Type::Int));
    // expr_builder.add_to_array(Expr_token("div", Type::Int));
    // expr_builder.add_to_array(Expr_token("(", Type::Unknown));
    // expr_builder.add_to_array(Expr_token("30", Type::Int));
    // expr_builder.add_to_array(Expr_token("+", Type::Int));
    // expr_builder.add_to_array(Expr_token("y", Type::Int));
    // expr_builder.add_to_array(Expr_token(")", Type::Unknown));
    // expr_builder.add_to_array(Expr_token("<=", Type::Int));
    // expr_builder.add_to_array(Expr_token("(", Type::Unknown));
    // expr_builder.add_to_array(Expr_token("xx", Type::Int));
    // expr_builder.add_to_array(Expr_token("*", Type::Int));
    // expr_builder.add_to_array(Expr_token("a", Type::Int));
    // expr_builder.add_to_array(Expr_token("+", Type::Int));
    // expr_builder.add_to_array(Expr_token("2", Type::Int));
    // expr_builder.add_to_array(Expr_token(")", Type::Unknown));
    // expr_builder.add_to_array(Expr_token(")", Type::Unknown));
    // expr_builder.add_to_array(Expr_token("e", Type::Int));
    // expr_builder.add_to_array(Expr_token("(", Type::Unknown));
    // expr_builder.add_to_array(Expr_token("zz", Type::Int));
    // expr_builder.add_to_array(Expr_token(">", Type::Int));
    // expr_builder.add_to_array(Expr_token("0", Type::Int));
    // expr_builder.add_to_array(Expr_token(")", Type::Unknown));

    // resultado = expr_builder.infix_to_postfix();

    // if (resultado != Type::Unknown) {
    //     std::cout << "O tipo resultante da expressão é: ";
    //     if (resultado == Type::Int) {
    //         std::cout << "int";
    //     } else if (resultado == Type::Bool) {
    //         std::cout << "bool";
    //     }
    //     std::cout << std::endl;
    // }
    
    // expr_builder.add_to_array(Expr_token("a", Type::Int));
    // expr_builder.add_to_array(Expr_token("+", Type::Int));
    // expr_builder.add_to_array(Expr_token("(", Type::Unknown));
    // expr_builder.add_to_array(Expr_token("-", Type::Int));
    // expr_builder.add_to_array(Expr_token("b", Type::Int));
    // expr_builder.add_to_array(Expr_token(")", Type::Unknown));

    // resultado = expr_builder.infix_to_postfix();



    // expr_builder.add_to_array(Expr_token("-", Type::Int));
    // expr_builder.add_to_array(Expr_token("a", Type::Int));
    // expr_builder.add_to_array(Expr_token("-", Type::Int));
    // expr_builder.add_to_array(Expr_token("(", Type::Unknown));
    // expr_builder.add_to_array(Expr_token("-", Type::Int));
    // expr_builder.add_to_array(Expr_token("b", Type::Int));
    // expr_builder.add_to_array(Expr_token(")", Type::Unknown));
    // // expr_builder.add_to_array(Expr_token("b", Type::Int));
    // expr_builder.add_to_array(Expr_token("<", Type::Bool));
    // // expr_builder.add_to_array(Expr_token("(", Type::Unknown));
    // expr_builder.add_to_array(Expr_token("-", Type::Int));

    // expr_builder.add_to_array(Expr_token("b", Type::Int, 0));
    // expr_builder.add_to_array(Expr_token("-", Type::Int));
    // expr_builder.add_to_array(Expr_token("(", Type::Unknown));
    // expr_builder.add_to_array(Expr_token("+", Type::Int));
    // expr_builder.add_to_array(Expr_token("b", Type::Int, 0));
    // expr_builder.add_to_array(Expr_token("+", Type::Int));
    // expr_builder.add_to_array(Expr_token("2", Type::Int));
    
    // // expr_builder.add_to_array(Expr_token(")", Type::Unknown));
    // expr_builder.add_to_array(Expr_token(")", Type::Unknown));

   
    // expr_builder.add_to_array(Expr_token("-", Type::Int));
    // expr_builder.add_to_array(Expr_token("a", Type::Int));
    // expr_builder.add_to_array(Expr_token("+", Type::Int));
    // expr_builder.add_to_array(Expr_token("b", Type::Int));
    // expr_builder.add_to_array(Expr_token("*", Type::Int));
    // expr_builder.add_to_array(Expr_token("(", Type::Int));
    // expr_builder.add_to_array(Expr_token("c", Type::Int));
    // expr_builder.add_to_array(Expr_token("*", Type::Int));
    // expr_builder.add_to_array(Expr_token("d", Type::Int));
    // expr_builder.add_to_array(Expr_token("-", Type::Int));
    // expr_builder.add_to_array(Expr_token("t", Type::Int));
    // expr_builder.add_to_array(Expr_token(")", Type::Int));
    // expr_builder.add_to_array(Expr_token("*", Type::Int));
    // expr_builder.add_to_array(Expr_token("(", Type::Int));
    // expr_builder.add_to_array(Expr_token("f", Type::Int));
    // expr_builder.add_to_array(Expr_token("+", Type::Int));
    // expr_builder.add_to_array(Expr_token("g", Type::Int));
    // expr_builder.add_to_array(Expr_token("*", Type::Int));
    // expr_builder.add_to_array(Expr_token("h", Type::Int));
    // expr_builder.add_to_array(Expr_token(")", Type::Int));
    // expr_builder.add_to_array(Expr_token("-", Type::Int));
    // expr_builder.add_to_array(Expr_token("i", Type::Int));

//     std::cout << "--------------------------" << std::endl;

//     // expr_builder.infix_to_postfix();

//     std::cout << "--------------------------" << std::endl;

//     // for(Expr_token element : array){
//     //     std::cout << "lexem: " << element.lexem << "  " << enum_to_string(element.type) << "  " << "address: " << std::endl;
//     // }
//     // std::cout << std::endl;

//     resultado = expr_builder.infix_to_postfix();

//     // Type resultado = Semantic_analyzer().validateExpression(array);
//     if (resultado != Type::Unknown) {
//         std::cout << "O tipo resultante da expressão é: ";
//         if (resultado == Type::Int) {
//             std::cout << "int";
//         } else if (resultado == Type::Bool) {
//             std::cout << "bool";
//         }
//         std::cout << std::endl;
//     }
// }

// void expression2(){
//     // generate("", "DALLOC", "", "3");
//     // generate("3", "ALLOC", "988", "");
//     // generate("5", "LDT", "24", "7");
//     string a;
//     int b = 1;

//     a = b;
//     cout << "valooor: " << a << "--- tipó: " << typeid(a).name() << endl;

}