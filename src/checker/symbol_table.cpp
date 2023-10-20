#include "symbol_table.h"
#include <fstream>
#include <iostream>
#include <string>
#include <stack>
#include "symbols.h"
#include "lexical/lexical_analyzer.h"

void Symbol_table::insert_record(Record *record){ //ajustar a fução que deve receber os parametros node e identificador
   if (!search_table(record->getLexem()) && record->getSymbol() == Symbols::SIDENTIFICADOR) {
        stack.push(*record);
    }else{
        std::cout << "já esta contido na tabela de simbolos" << std:: endl;
    }
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

void Record::setSymbol(Symbols sy){
    symbol = sy;
}

 Symbols Record::getSymbol(){
    return symbol;
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

////////////////////////////TRECHO PARA TESTES DA TABELA DE SIMBOLO////////////////////////////
//inserir elas entre as linhas 18 e 32 do arquivo parser
// lexical.next_token();
//     lexical.next_token();
//     std::cout << lexical.get_current_token().symbol << std::endl;
//     std::cout << lexical.get_current_token().lexem << std::endl;

//     while(lexical.get_current_token().symbol != Symbols::SPONTO){
//         record.setLexem(lexical.get_current_token().lexem);
//         record.setSymbol(lexical.get_current_token().symbol);
//         record.setScope(true);
//         record.setType("asdad");
//         record.setAddress(0);
//         symbol_table.insert_record(&record);
//         lexical.next_token();
//     }
//     symbol_table.print_table();
/////////////////////////////////////////