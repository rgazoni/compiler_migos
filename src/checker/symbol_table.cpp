#include "symbol_table.h"
#include <fstream>
#include <iostream>
#include <string>
#include <stack>
#include "symbols.h"
#include "lexical/lexical_analyzer.h"
#include "./error/Errors.h"

void Symbol_table::insert_record_variable(Record *record){ 
   if (!is_variable_exists(record->getLexem()) && record->getSymbol() == Symbols::SIDENTIFICADOR && record->getScope() == false) { 
        stack.push(*record);
   }else{
        //raiseError(Error::EXPECTED_ANOTHER_VARIABLE_NAME);
   }
}

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

//insere na pilha o nome de funções e o nome do programa
void Symbol_table::insert_record_function(Record *record){ 
     if (!is_function_exists(record->getLexem()) && record->getSymbol() == Symbols::SIDENTIFICADOR && record->getScope() == true) { 
        stack.push(*record);
     } else {
        //raiseError(Error::EXPECTED_ANOTHER_FUNCTION_NAME);
     }
}

bool Symbol_table::is_function_exists(const std::string& lexem) {
    std::stack<Record> auxStack = stack; 
    while (!auxStack.empty()) {
        Record record = auxStack.top();
        if (record.getLexem() == lexem && record.getScope() == true) {
            std::cout << "lexema encontrado:" << lexem << std::endl;
            return true; 
        }
        auxStack.pop();
    }
    return false; 
}

//percorre a pilha e desempilha todas as variavies ja usadas no escopo de uma função
void Symbol_table::pop_scope(){
    while(!stack.empty()){
        if(stack.top().getScope() == false){
            stack.pop();
        }else if(stack.top().getScope() == true){
           stack.top().setScope(false);
           break; 
        }
    }
}

//Percorre a tabela de simbolo
bool Symbol_table::search_identifier(const std::string& lexem) {
    std::stack<Record> auxStack = stack;
    while (!auxStack.empty()) {
        Record record = auxStack.top();
        if (record.getLexem() == lexem && record.getScope() == false) {
            std::cout << "variavel encontrada" << lexem << std::endl;
            return true;
        }
        auxStack.pop(); 
    }
    return false;
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

//getters e setters
void Record::setLexem(std::string l){
    lexem = l;
}

std::string Record::getLexem(){
    return lexem;
}

void Record::setSymbol(Symbols sy){
    symbol = sy;
}

 Symbols Record::getSymbol(){
    return symbol;
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
