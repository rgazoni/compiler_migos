#include "symbol_table.h"
#include <fstream>
#include <iostream>
#include <string>
#include <stack>
#include "symbols.h"
#include "lexical/lexical_analyzer.h"
#include "./error/Errors.h"

std::stack<Record> Symbol_table::stack;

void Symbol_table::insert_record_variable(Record *record){ 
   if (!is_variable_exists(record->getLexem()) && record->getScope() == false) { 
        stack.push(*record);
   }else{
        raiseError(Error::EXPECTED_ANOTHER_VARIABLE_NAME);
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


//insere na pilha o nome de procedimentos e o nome do programa
void Symbol_table::insert_record_procedure(Record *record){ 
     if (!is_procedure_exists(record->getLexem()) && record->getScope() == true) { 
        stack.push(*record);
     } else {
        raiseError(Error::EXPECTED_ANOTHER_PROCEDURE_NAME);
     }
}

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

//insere na pilha nomes de funções tem que fazer ainda
void Symbol_table::insert_record_function(Record *record){
    if (!is_procedure_exists(record->getLexem()) && record->getScope() == true) { 
        stack.push(*record);
     } else {
        raiseError(Error::EXPECTED_ANOTHER_FUNCTION_NAME);
     }
}

bool Symbol_table::is_function_exists(const std::string& lexem){
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

//Analisar possiveis erros que podem ocorrer na busca e inserção de nomes de funções e elaborar
//uma mensagem de erro se precisar
//OBSERVAÇÃO: se o for mesmo utilizar o escopo de função como true igual a de procedimentos,
//ficar atento que pode cagar a função de desempilhar. Tentar ver se com o escopo igual a false
//nao fica mais facil

//DUVIDAS PARA O FREITAS
//como identificar o tipo de função quando for inserida na tabela de simbolos
//como identificar o tipo de variavel quando for inserida na tabela de simbolos
//entender a implemntação das funções analisa chamada de função e chamada de procedimento
//como testaria pra ver se é uma função

//Insere_tabela(token.lexema,””,nível,rótulo) - perguntar quais os parametros da função que vao ser
//e como inserir a função na tabela de simbolos

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

//Percorre a tabela de simbolo //retornar o endereço
bool Symbol_table::search_identifier(const std::string& lexem) {
    std::stack<Record> auxStack = stack;
    while (!auxStack.empty()) {
        Record record = auxStack.top();
        if (record.getLexem() == lexem && record.getScope() == false) {
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

Record::Record(std::string lexem, std::string type, bool scope, int address)
    : lexem(lexem), type(type), scope(scope), address(address) {}

Symbol_table::Symbol_table() {
    // Inicialize os membros da classe, se necessário
}

//getters e setters
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
