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

template <typename T>
class MyStack {
private:
    std::stack<T> data;

public:
    void push(const T& value) {
        data.push(value);
    }

    void pop() {
        if (!data.empty()) {
            std::cout << "Removing value: " << data.top() << std::endl;
            data.pop();
        } else {
            std::cerr << "Stack underflow!" << std::endl;
        }
    }

    void printStack() const {
        std::stack<T> tempStack = data;  // Cria uma cópia da pilha original
        std::cout << "Stack: ";
        while (!tempStack.empty()) {
            std::cout << tempStack.top() << " ";
            tempStack.pop();
        }
        std::cout << std::endl;
    }
};


void expression(){
    MyStack<int> myStack;

    // Empilha alguns valores para teste
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Imprime a pilha antes da função pop personalizada
    std::cout << "Before custom pop:" << std::endl;
    myStack.printStack();

    // Chama a função pop personalizada
    myStack.pop();

    // Imprime a pilha após a função pop personalizada
    std::cout << "After custom pop:" << std::endl;
    myStack.printStack();
}