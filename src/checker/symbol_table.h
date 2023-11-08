#ifndef symbol_table_h
#define symbol_table_h

#include <fstream>
#include <iostream>
#include <stack>
#include "symbols.h"

class Record{
    private:
    std::string lexem;
    Symbols symbol;
    bool scope;
    std::string type; 
    int address;
    
    public:
    void setLexem(std::string l);
    std::string getLexem();
    void setSymbol(Symbols sy);
    Symbols getSymbol();
    void setScope(bool s);
    bool getScope();
    void setType(std::string t);
    std::string getType();
    void setAddress(int a);
    int getAddress();
    
};

class Symbol_table{
    private:
    std::stack<Record> stack;
    public:
    void insert_record_variable(Record *record);
    void insert_record_function(Record *record);
    void pop_scope();
    bool search_identifier(const std::string& lexem);
    bool search_variable_table(const std::string& lexem);
    bool search_function_table(const std::string& lexem);   
    void print_table();
};

#endif