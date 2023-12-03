#ifndef DVM_H
#define DVM_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <thread>

class MainWindow;

using namespace std;

class DVM {
public:
    void executeFromFile(const std::string& filename);
    void displayState();
    static string getS();
    static string getPC();
    static void setS(int newValue);
    static void setPC(int newValue);
    static std::vector<int> M;
    // static void ALLOC(string current_address, string var_amount);
    // void DALLOC(string current_address, string var_amount);
    // static void STR(string variable);
    // std::thread thread;

    DVM();
    ~DVM();

    static bool isDataAvailable;
    static int sharedData;
    static std::condition_variable dataReady;


private:
    static int S;
    static int PC;

    void initialize_variables();

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
    void STR(string variable);
    void ALLOC(string current_address, string var_amount);
    void DALLOC(string current_address, string var_amount);
    void CALL(string address);
    void RETURN();
    void RD();
    void PRN();

    std::mutex dataMutex;

};

#endif