#include <iostream>
#include <typeinfo>
#include "expression_builder.h"
#include "error/Errors.h"
#include "lexical/lexical_analyzer.h"
#include "symbols.h"
#include "semantic_analyzer.h"
#include "tests.h"
#include "generate.h"
#include "DVM.h"

#include <iostream>
#include <cctype>
#include <string>
#include <stack>


using namespace std;

void expression(){
    DVM dvm;

    // Empilha alguns valores para teste
    DVM::M.push_back(10);
    DVM::M.push_back(20);
    DVM::M.push_back(30);
    DVM::M.push_back(40);
    DVM::M.push_back(50);
    DVM::M.push_back(60);


    // Imprime a pilha antes da função pop personalizada
    std::cout << "Before custom pop:" << std::endl;
    dvm.displayState();

    // Chama a função pop personalizada

    // Imprime a pilha após a função pop personalizada
    std::cout << "After custom pop:" << std::endl;
    dvm.displayState();

}