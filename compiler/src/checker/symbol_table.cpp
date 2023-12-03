#include "symbol_table.h"
#include <fstream>
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include "symbols.h"
#include "lexical/lexical_analyzer.h"
#include "./error/Errors.h"

using namespace std;

std::stack<Record> Symbol_table::stack;
int Symbol_table::dalloc_var = 0;

//DUVIDAS PARA O FREITAS
//como identificar o tipo de função quando for inserida na tabela de simbolos
//como identificar o tipo de variavel quando for inserida na tabela de simbolos
//entender a implemntação das funções analisa chamada de função e chamada de procedimento
//como testaria pra ver se é uma função

//insere variavel 
void Symbol_table::insert_record_variable(Record *record){ 
   if (!is_variable_exists(record->getLexem()) && record->getScope() == false) { 
        stack.push(*record);
   }else{
        raiseError(Error::EXPECTED_ANOTHER_VARIABLE_NAME);
   }
}

//pesquisa por variavel duplicada
bool Symbol_table::is_variable_exists(const std::string& lexem) {
    std::stack<Record> auxStack = stack; 
    Record topRecord = auxStack.top();
    while(topRecord.getScope() == false){
        topRecord = auxStack.top();
        if (topRecord.getLexem() == lexem) {
            return true;
        }
        auxStack.pop();
    }
    return false;
}

void reverseStack(std::stack<Record>& stack) {
    size_t size = stack.size();
    std::vector<Record> elements;

    elements.reserve(size);

    // Store stack elements in the vector
    while (!stack.empty()) {
        elements.push_back(stack.top());
        stack.pop();
    }

    // Reinsert elements into the stack in reverse order
    for (size_t i = 0; i < size; ++i) {
        stack.push(elements[i]);
    }
}

Symbols Symbol_table::get_variable_type(const std::string& lexem) {
    std::stack<Record> auxStack = stack; 
    Record topRecord = auxStack.top();

    while(topRecord.getScope() == false){
        topRecord = auxStack.top();
        if (topRecord.getLexem() == lexem) {
            if(topRecord.getType() == "SINTEIRO")
                return Symbols::SINTEIRO;
            if(topRecord.getType() == "SBOOLEANO")
                return Symbols::SBOOLEANO;
        }
        auxStack.pop();
    }

    while(!auxStack.empty()){
        topRecord = auxStack.top();

        if (topRecord.getLexem() == lexem) {
            if(topRecord.getType() == "SINTEIRO"){
                return Symbols::SINTEIRO;
            }
            if(topRecord.getType() == "SBOOLEANO"){
                return Symbols::SBOOLEANO;
            }
        }
        auxStack.pop();
    }

    return Symbols::SDESCONHECIDO;
}

int Symbol_table::get_variable_address(const std::string& lexem) {
    std::stack<Record> auxStack = stack; 
    Record topRecord = auxStack.top();
    int addressValue;

    while(topRecord.getScope() == false){
        topRecord = auxStack.top();
        if (topRecord.getLexem() == lexem) {
            addressValue = topRecord.getAddress();
            return addressValue;
        }
        auxStack.pop();
    }

    while(!auxStack.empty()){
        topRecord = auxStack.top();

        if (topRecord.getLexem() == lexem) {
            addressValue = topRecord.getAddress();
            return addressValue;
        }
        auxStack.pop();
    }

    return 0;
}

int Symbol_table::get_procedure_label(const std::string& lexem) {
    std::stack<Record> auxStack = stack; 
    Record topRecord = auxStack.top();
    int label;

    while(!auxStack.empty()){
        topRecord = auxStack.top();
        if (topRecord.getType() == "SPROCEDIMENTO" && topRecord.getLexem() == lexem) {
            label = topRecord.getAddress();
            return label;
        }
        auxStack.pop();
    }

    return 0;
}

int Symbol_table::get_function_label(const std::string& lexem) {
    std::stack<Record> auxStack = stack; 
    Record topRecord = auxStack.top();
    int label;

    while(!auxStack.empty()){
        topRecord = auxStack.top();
        if ((topRecord.getType() == "S_FUNCAO_INTEIRO" || topRecord.getType() == "S_FUNCAO_BOOLEANO") && topRecord.getLexem() == lexem) {
            label = topRecord.getAddress();
            return label;
        }
        auxStack.pop();
    }
    return 0;
}

int Symbol_table::get_function_scope(const std::string& lexem) {
    std::stack<Record> auxStack = stack; 
    Record topRecord = auxStack.top();
    int scope;

    while(!auxStack.empty()){
        topRecord = auxStack.top();
        if ((topRecord.getType() == "S_FUNCAO_INTEIRO" || topRecord.getType() == "S_FUNCAO_BOOLEANO") && topRecord.getLexem() == lexem) {
            if(topRecord.getScope() == true)
                return 1;
            else
                return 0;
        }

        auxStack.pop();
    }

    return -1;
}

Symbols Symbol_table::get_function_type(const std::string& lexem) {
    std::stack<Record> auxStack = stack; 
    Record topRecord = auxStack.top();

    //  while(topRecord.getScope() == false){
    //     topRecord = auxStack.top();
    //     if (topRecord.getLexem() == lexem) {
    //         if(topRecord.getType() == "S_FUNCAO_INTEIRO")
    //             return Symbols::SINTEIRO;
    //         if(topRecord.getType() == "S_FUNCAO_BOOLEANO")
    //             return Symbols::SBOOLEANO;
    //     }
    //     auxStack.pop();
    // }

    while(!auxStack.empty()){
        topRecord = auxStack.top();

        if (topRecord.getLexem() == lexem) {
            if(topRecord.getType() == "S_FUNCAO_INTEIRO"){
                return Symbols::SINTEIRO;
            }
            if(topRecord.getType() == "S_FUNCAO_BOOLEANO"){
                return Symbols::SBOOLEANO;
            }
        }
        auxStack.pop();
    }

    return Symbols::SDESCONHECIDO;
}

bool Symbol_table::search_function(const std::string& lexem){
    std::stack<Record> auxStack = stack;
    while (!auxStack.empty()) {
        Record topRecord = auxStack.top();
        if ((topRecord.getType() == "S_FUNCAO_INTEIRO" || topRecord.getType() == "S_FUNCAO_BOOLEANO") && topRecord.getLexem() == lexem) {
            std::cout << lexem << std::endl;
            std::cout << topRecord.getType() << std::endl;
            return true;
        } 
        auxStack.pop();
    }
    return false;
}

//coloca tipo na variavel
void Symbol_table::update_variable_type(const std::string& lexem) {
    int count = 0;
    std::stack<Record> auxStack;
    if (!stack.empty()) {
        Record topRecord = stack.top();
        while (!topRecord.getScope()) {
            if (lexem.compare("inteiro") == 0 && topRecord.getType().empty()) {
                topRecord.setType("SINTEIRO");
                auxStack.push(topRecord);
            } else if (lexem.compare("booleano") == 0 && topRecord.getType().empty()) {
                topRecord.setType("SBOOLEANO");
                auxStack.push(topRecord);
            } else if (!topRecord.getType().empty()) {
                auxStack.push(topRecord);
            }
            stack.pop();
            count++;
            if (!stack.empty()) {
                topRecord = stack.top();
            } else {
                break;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        stack.push(auxStack.top());
        auxStack.pop();
    }
}


//insere na pilha o nome de procedimentos, funções e o nome do programa
void Symbol_table::insert_record_procedure(Record *record){ 
     if (!is_procedure_exists(record->getLexem()) && record->getScope() == true) { 
        stack.push(*record);
     } else {
        raiseError(Error::EXPECTED_ANOTHER_PROCEDURE_NAME);
     }
}

//pesquisa por procedimento dublicado
bool Symbol_table::is_procedure_exists(const std::string& lexem) {
    std::stack<Record> auxStack = stack; 
    while (!auxStack.empty()) {
        Record record = auxStack.top();
        if (record.getLexem() == lexem && record.getScope() == true) {
            return true; 
        }
        auxStack.pop();
    }
    return false; 
}

//coloca tipo nas funções
void Symbol_table::update_function_type(const std::string& lexem){
    int count = 0;
    std::stack<Record> auxStack;
    if (!stack.empty()) {
        Record topRecord = stack.top();
        while (topRecord.getScope()) {
            if (lexem.compare("inteiro") == 0 && topRecord.getType().empty()) {
                topRecord.setType("S_FUNCAO_INTEIRO");
                auxStack.push(topRecord);
            } else if (lexem.compare("booleano") == 0 && topRecord.getType().empty()) {
                topRecord.setType("S_FUNCAO_BOOLEANO");
                auxStack.push(topRecord);
            } else if (!topRecord.getType().empty()) {
                auxStack.push(topRecord);
            }
            stack.pop();
            count++;
            if (!stack.empty()) {
                topRecord = stack.top();
            } else {
                break;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        stack.push(auxStack.top());
        auxStack.pop();
    }
}

//percorre a pilha e desempilha todas as variavies ja usadas no escopo de uma função
void Symbol_table::pop_scope(){
    while(!stack.empty()){
        if(!stack.top().getScope()){
            if(stack.top().getType() == "S_FUNCAO_INTEIRO" || stack.top().getType() == "S_FUNCAO_BOOLEANO" || stack.top().getType() == "SPROCEDIMENTO") {
                stack.pop();

            } else{
                stack.pop();
                dalloc_var++;
            }

        }else if(stack.top().getScope()){
           stack.top().setScope(false);
           break; 
        }
    }
}

//verifica se a variavel foi declarada para ser usada nos comandos leia ou escreva
//retornar o endereço (em construção)
bool Symbol_table::search_identifier(const std::string& lexem) {
    std::stack<Record> auxStack = stack;
    while (!auxStack.empty()) {
        Record record = auxStack.top();
        if (record.getLexem() == lexem && !record.getScope()) {
            return true;
        }
        auxStack.pop(); 
    }
    raiseError(Error::EXPECTED_VARIABLE_DECLARATION);
}

//imprime a tabela de simbolos
void Symbol_table::print_table() {
    std::stack<Record> auxStack = stack;
    while (!auxStack.empty()) {
        Record record = auxStack.top();
        std::cout << "Lexema: " << record.getLexem() << std::endl;
        std::cout << "Scope: " << (record.getScope()) << std::endl;
        std::cout << "Type: " << record.getType() << std::endl;
        std::cout << "Address: " << record.getAddress() << std::endl;
        std::cout << "---------------" << std::endl;
        auxStack.pop();
    }
}

//construtor da classe record
Record::Record(std::string lexem, std::string type, bool scope, int address)
    : lexem(lexem), type(type), scope(scope), address(address) {}

Symbol_table::Symbol_table() {
    // Inicialize os membros da classe, se necessário
}

//getters e setters da classe Record
void Record::setLexem(std::string l){
    lexem = l;
}

std::string Record::getLexem(){
    return lexem;
}

void Record::setScope(bool s){
    scope = s;
}

bool Record::getScope(){
    return scope;
}

void Record::setType(std::string t){
    type = t;
}

std::string Record::getType(){
    return type;
}

void Record::setAddress(int a){
    address = a;
}

int Record::getAddress(){
    return address;
}
