#ifndef symbol_table_h
#define symbol_table_h

#include <fstream>
#include <iostream>
#include <stack>

class Record{
    private:
    std::string lexem;
    bool scope;
    std::string type; 
    int address;
    
    public:
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
    std::stack<Record> stack;
    public:
    void insert_record(Record *record); 
    bool search_table(const std::string& lexem);   
    void print_table();
};

#endif