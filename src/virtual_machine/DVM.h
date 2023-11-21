#ifndef DVM_H
#define DVM_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <stack>


using namespace std;

class DVM {
public:
    void executeFromFile(const std::string& filename);
    void displayState();
    static string getS();
    static string getPC();
    static void setS(int newValue);
    static void setPC(int newValue);
    static std::stack<int> M;
    void ALLOC(string current_available_address, string var_count);
    void DALLOC(string var_count);


private:
    static int S;
    static int PC;

    void LDC(string k);
    void LDV(string n);
    void ADD();
    void SUB();
    void MULT();
    void DIVI();
    void INV();
    void AND();
    void OR();
    void NEG();
    void CME();
    void CMA();
    void CEQ();
    void CDIF();
    void CMEQ();
    void CMAQ();
    void JMP(string label);
    void JMPF(string label);
    void STR(int variableIndex);
    
};

#endif