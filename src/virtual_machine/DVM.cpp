#include "DVM.h"
#include <iostream>
#include <cctype>
#include <string>

using namespace std;

DVM::DVM() : S(-1), PC(0) {}

bool isDigit(string s){
    bool isDigit = true;

    try {
        for (char c : s) {
            if (!std::isdigit(c)) {
                isDigit = false;
                break;  // No need to check further once a non-digit character is found
            }
        }

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return isDigit;
}

void DVM::executeFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    std::string command = "";

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        iss >> command;

        std::cout << "command1: " << command << std::endl;
        if(isDigit(command) || command == "NULL")
            iss >> command;

        std::cout << "command2: " << command << std::endl;

        if (command == "LDV") {
            string variable;
            if (iss >> variable) {
                LDV(variable); // Convert character to index
            }
        } else if (command == "LDC") {
            string constant;
            if (iss >> constant) {
                LDC(constant);
            }
        } else if (command == "ADD") {
            ADD();
        } else if (command == "SUB") {
            SUB();
        } else if (command == "MULT") {
            MULT();
        } else if (command == "DIVI") {
            DIVI();
        } else if (command == "INV") {
            INV();
        } else if (command == "AND") {
            AND();
        } else if (command == "OR") {
            OR();
        } else if (command == "NEG") {
            NEG();
        } else if (command == "CME") {
            CME();
        } else if (command == "CMA") {
            CMA();
        } else if (command == "CEQ") {
            CEQ();
        } else if (command == "CDIF") {
            CDIF();
        } else if (command == "CMEQ") {
            CMEQ();
        } else if (command == "CMAQ") {
            CMAQ();
        } else if (command == "JMP") {
            std::string label;
            if (iss >> label) {
                // JMP(label);
            }
        } else if (command == "JMPF") {
            std::string label;
            if (iss >> label) {
                // JMPF(label);
            }
        } else if (command == "STR") {
            char variable;
            if (iss >> variable) {
                // STR(variable - 'A'); // Convert character to index
            }
        }
    
        PC++;
        displayState();
    }

    file.close();
}


// Exibir estado atual
void DVM::displayState() {
    std::cout << "Stack: ";
    for (int i = 0; !M.empty() ; ++i) {
        std::cout << M[i] << " | ";
    }
    std::cout << "\n" << "PC: " << PC << "\n";
}

// Carregar constante
void DVM::LDC(string k) {
    S++;
    M[S] = stoi(k);
}

// Carregar valor
void DVM::LDV(string n) {
    S++;
    M[S] = M[stoi(n)];
}

// Somar
void DVM::ADD() {
    M[S - 1] += M[S];
    S--;
}

// Subtrair
void DVM::SUB() {
    M[S - 1] -= M[S];
    S--;
}

// Multiplicar
void DVM::MULT() {
    M[S - 1] *= M[S];
    S--;
}

// Dividir
void DVM::DIVI() {
    M[S - 1] /= M[S];
    S--;
}

// Inverter sinal
void DVM::INV() {
    M[S] = -M[S];
}

// Conjunção
void DVM::AND() {
    if (M[S - 1] == 1 && M[S] == 1)
        M[S - 1] = 1;
    else
        M[S - 1] = 0;
    S--;
}

// Disjunção
void DVM::OR() {
    if (M[S - 1] == 1 || M[S] == 1)
        M[S - 1] = 1;
    else
        M[S - 1] = 0;
    S--;
}

// Negação
void DVM::NEG() {
    M[S] = 1 - M[S];
}

// Comparar menor
void DVM::CME() {
    if (M[S - 1] < M[S])
        M[S - 1] = 1;
    else
        M[S - 1] = 0;
    S--;
}

// Comparar maior
void DVM::CMA() {
    if (M[S - 1] > M[S])
        M[S - 1] = 1;
    else
        M[S - 1] = 0;
    S--;
}

// Comparar igual
void DVM::CEQ() {
    if (M[S - 1] == M[S])
        M[S - 1] = 1;
    else
        M[S - 1] = 0;
    S--;
}

// Comparar desigual
void DVM::CDIF() {
    if (M[S - 1] != M[S])
        M[S - 1] = 1;
    else
        M[S - 1] = 0;
    S--;
}

// Comparar menor ou igual
void DVM::CMEQ() {
    if (M[S - 1] <= M[S])
        M[S - 1] = 1;
    else
        M[S - 1] = 0;
    S--;
}

// Comparar maior ou igual
void DVM::CMAQ() {
    if (M[S - 1] >= M[S])
        M[S - 1] = 1;
    else
        M[S - 1] = 0;
    S--;
}
