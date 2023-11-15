#ifndef DVM_H
#define DVM_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

class DVM {
public:
    DVM();
    void executeFromFile(const std::string& filename);
    void displayState();

private:
    std::vector<int> M;
    static int S;
    int PC;

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
    void JMP(const std::string& label);
    void JMPF(const std::string& label);
    void STR(int variableIndex);
};

#endif