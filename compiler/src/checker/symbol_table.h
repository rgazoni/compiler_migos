#ifndef symbol_table_h
#define symbol_table_h

#include <fstream>
#include <iostream>
#include <stack>
#include "symbols.h"

class Record{
    private:
    std::string lexem;
    std::string type; 
    bool scope;
    int address;

    public:

    Record(std::string lexem, std::string type, bool scope, int address);
    
    void setLexem(std::string l);
    std::string getLexem();
    void setScope(bool s);
    bool getScope();
    void setType(std::string t);
    std::string getType();
    void setAddress(int a);
    int getAddress();
    
};

class Symbol_table{
    private:
    static std::stack<Record> stack;
    public:

    Symbol_table();
    static int dalloc_var;

    void insert_record_variable(Record *record);
    bool is_variable_exists(const std::string& lexem);
    void update_variable_type(const std::string& lexem);
    Symbols get_variable_type(const std::string& lexem);
    void insert_record_procedure(Record *record);
    bool is_procedure_exists(const std::string& lexem);
    void update_function_type(const std::string& lexem);
    void pop_scope();
    bool search_identifier(const std::string& lexem);
    int get_variable_address(const std::string& lexem); 
    int get_function_scope(const std::string& lexem);
    void print_table();
    Symbols get_function_type(const std::string& lexem);
    int get_procedure_label(const std::string& lexem);
    int get_function_label(const std::string& lexem);
    bool search_function(const std::string& lexem);
};

#endif