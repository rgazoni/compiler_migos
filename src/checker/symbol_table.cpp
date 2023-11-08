#include "symbol_table.h"
#include <fstream>
#include <iostream>
#include <string>
#include <stack>
#include "symbols.h"
#include "lexical/lexical_analyzer.h"

void Symbol_table::insert_record_variable(Record *record){ 
   if (!search_variable_table(record->getLexem()) && record->getSymbol() == Symbols::SIDENTIFICADOR && record->getScope() == false) { 
        stack.push(*record);
   }else{
        std::cout << "variavel já declarada" << std:: endl;
        //colocar mensagem de erro caso haja uma variavel repetida no mesmo escopo
   }
}

//insere na pilha o nome de funções e o nome do programa
void Symbol_table::insert_record_function(Record *record){ 
     if (!search_function_table(record->getLexem()) && record->getSymbol() == Symbols::SIDENTIFICADOR && record->getScope() == true) { 
        stack.push(*record);
     } else {
        std::cout << "nome de função ou programa já declarado" << std:: endl;
        //colocar mensagem de erro caso haja uma funcao repetida no mesmo escopo
     }
}

//percorre a pilha para desempilhar as variaveis que ja foram usadas de uma função
void Symbol_table::pop(){
    while(!stack.empty()){
        Record topRecord = stack.top();
        if(topRecord.getScope() == false){
            stack.pop();
        }else {
           topRecord.setScope(false);
           break; 
        }
    }
}

//percorrer a pilha verificando se todas as variaveis de um scopo estao ok
//se chegar no final da pilha e nao achar, retornar uma mensagem de erro

bool Symbol_table::search_variable_table(const std::string& lexem) {
    std::stack<Record> auxStack = stack; 
    Record topRecord = auxStack.top();
    while(topRecord.getScope() == false){
        topRecord = auxStack.top();
        if (topRecord.getLexem() == lexem) {
            std::cout << "variavel ja declarada" << lexem << std::endl;
            //colocar uma mensagem de erro
            return true; // O lexema foi encontrado na tabela
        }
        auxStack.pop();
    }
    
    return false; // O lexema não foi encontrado na tabela
}


// Percorre a tabela de simbolo
// bool Symbol_table::iterate_through_symbol_table(const std::string& lexem) {
//     std::stack<Record> auxStack = stack;
//     // percorre pilha até chegar no fim dela
//     while (!stack.empty()) {
//         Record record = auxStack.top();
//         // se o lexema vindo do parametro for igual ao campo atual da tabela, esta declaradoa ou seja retorna true
//         if (record.getLexem() == lexem && record.getScope() == false) {
//             return true;
//         } else if (record.getScope() == true){ 
//             auxStack.pop();
//         } else { //variavel nao esta na tabela de simbolo entao retorna erro
//             //ERRO
//         }
//         auxStack.pop();
//     }
// }

bool Symbol_table::search_function_table(const std::string& lexem) {
    std::stack<Record> auxStack = stack; 
    while (!auxStack.empty()) {
        Record record = auxStack.top();
        if (record.getLexem() == lexem && record.getScope() == true) {
            std::cout << "lexema encontrado:" << lexem << std::endl;
            //colocar uma mensagem de erro
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
        std::cout << "Scope: " << (record.getScope()) << std::endl;
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