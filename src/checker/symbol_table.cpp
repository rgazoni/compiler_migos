#include "symbol_table.h"
#include <fstream>
#include <iostream>
#include <string>
#include <stack>

void Symbol_table::insert_record(Record *record){ //ajustar a fução que deve receber os parametros node e identificador
   stack.push(*record);
}

bool Symbol_table::search_table(const std::string& lexem){
    std::stack<Record> auxStack = stack; //pilha auxiliar 
    while(!auxStack.empty()){
        Record record = auxStack.top();
        if(record.getLexem() == lexem){
            std::cout << lexem << std::endl;
            return true; // O lexema foi encontrado na tabela
        }
        auxStack.pop();
    }
    return false; // O lexema não foi encontrado na tabela
}

void Symbol_table::print_table() {
    std::stack<Record> auxStack = stack;
    while (!auxStack.empty()) {
        Record record = auxStack.top();
        std::cout << "Lexema: " << record.getLexem() << std::endl;
        std::cout << "Scope: " << (record.getScope() ? "Global" : "Local") << std::endl;
        std::cout << "Type: " << record.getType() << std::endl;
        std::cout << "Address: " << record.getAddress() << std::endl;
        std::cout << "---------------" << std::endl;
        
        auxStack.pop();
    }
}

void Record::setLexem(std::string l){
    lexem = l;
}

std::string Record::getLexem(){
    return lexem;
}

void Record:: setScope(bool s){
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

