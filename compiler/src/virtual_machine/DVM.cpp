#include "DVM.h"
#include <iostream>
#include <cctype>
#include <string>
#include <stack>
#include <vector>
#include <fstream>



using namespace std;

int DVM::S = -1;
int DVM::PC = 0;
std::vector<int> DVM::M(1000);
std::ifstream globalFile;

bool isDigit(string s){
    bool isDigit = true;
   
    for (char c : s) {
        if (!std::isdigit(c)) {
            isDigit = false;
            break;  // No need to check further once a non-digit character is found
        }
    }
    
    return isDigit;
}

string DVM::getS() {
    return to_string(S);
}

string DVM::getPC() {
    return to_string(PC);
}

void DVM::setS(int newValue) {
    S = newValue;
}

void DVM::setPC(int newValue) {
    PC = newValue;
}

void DVM::executeFromFile(const std::string& filename) {
    globalFile.open(filename);
    if (!globalFile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    std::string command = "";

    while (std::getline(globalFile, line)) {
        std::istringstream iss(line);
        iss >> command;
        cout << "command: " << command << endl;

        // std::cout << "command1: " << command << std::endl;
        // if()
        //     iss >> command;

        // std::cout << "command2: " << command << std::endl;
        if (isDigit(command)) {
            string instruction;

            iss >> instruction;
            if (instruction == "NULL") {
                PC++;
            }
        } else if (command == "START") {
            S = -1;
            PC++;
        } else if (command == "LDV") {
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
                JMP(label);
            }
        } else if (command == "JMPF") {
            std::string label;
            if (iss >> label) {
                JMPF(label);
            }
        } else if (command == "STR") {
            string variable;
            if (iss >> variable) {
                STR(variable);
            }
        } else if (command == "ALLOC") {
            string address;
            string var_count;
            iss >> address;
            if(iss >> var_count) {
                ALLOC(address, var_count);
            }    
        } else if (command == "DALLOC") {
            string address;
            string var_count;
            iss >> address;
            if(iss >> var_count) {
                DALLOC(address, var_count);
            }    
        } else if (command == "CALL") {
            string address;
            if (iss >> address) {
                CALL(address);
            }
        } else if (command == "RETURN") {
            RETURN();
        } else if (command == "HLT") {
            PC = 0;
            return;
        } else if (command == "RD") {
            RD();
            // return;
        } else if (command == "PRN") {
            PRN();
        } else {
            PC++;
        }

        displayState();

    }

    globalFile.close();
}


// Exibir estado atual
void DVM::displayState() {
    string a;
    std::cout << "Stack: ";
    for (int i = 0; i < 15 ; i++) {
        std::cout << M[i] << " | ";
    }
    std::cout << "\n" << "PC: " << PC << " - S: " << S << "\n";
    cin >> a;
}

// Carregar constante
void DVM::LDC(string k) {
    S++;
    M[S] = stoi(k);
    PC++;
}

// Carregar valor
void DVM::LDV(string n) {
    S++;
    M[S] = M[stoi(n)];
    PC++;
}

// Somar
void DVM::ADD() {
    M[S - 1] += M[S];
    S--;
    PC++;
}

// Subtrair
void DVM::SUB() {
    M[S - 1] -= M[S];
    S--;
    PC++;
}

// Multiplicar
void DVM::MULT() {
    M[S - 1] *= M[S];
    S--;
    PC++;
}

// Dividir
void DVM::DIVI() {
    M[S - 1] /= M[S];
    S--;
    PC++;
}

// Inverter sinal
void DVM::INV() {
    M[S] = -M[S];
    PC++;
}

// Conjunção
void DVM::AND() {
    if (M[S - 1] == 1 && M[S] == 1)
        M[S - 1] = 1;
    else
        M[S - 1] = 0;
    S--;
    PC++;
}

// Disjunção
void DVM::OR() {
    if (M[S - 1] == 1 || M[S] == 1)
        M[S - 1] = 1;
    else
        M[S - 1] = 0;
    S--;
    PC++;
}

// Negação
void DVM::NEG() {
    M[S] = 1 - M[S];
    PC++;
}

// Comparar menor
void DVM::CME() {
    if (M[S - 1] < M[S])
        M[S - 1] = 1;
    else
        M[S - 1] = 0;
    S--;
    PC++;
}

// Comparar maior
void DVM::CMA() {
    if (M[S - 1] > M[S])
        M[S - 1] = 1;
    else
        M[S - 1] = 0;
    S--;
    PC++;
}

// Comparar igual
void DVM::CEQ() {
    if (M[S - 1] == M[S])
        M[S - 1] = 1;
    else
        M[S - 1] = 0;
    S--;
    PC++;
}

// Comparar desigual
void DVM::CDIF() {
    if (M[S - 1] != M[S])
        M[S - 1] = 1;
    else
        M[S - 1] = 0;
    S--;
    PC++;
}

// Comparar menor ou igual
void DVM::CMEQ() {
    if (M[S - 1] <= M[S])
        M[S - 1] = 1;
    else
        M[S - 1] = 0;
    S--;
    PC++;
}

// Comparar maior ou igual
void DVM::CMAQ() {
    if (M[S - 1] >= M[S])
        M[S - 1] = 1;
    else
        M[S - 1] = 0;
    S--;
    PC++;
}

void DVM::JMP(string label) {
    string line;

    PC = stoi(label);
    globalFile.seekg(0);

    for (int i=0; i < PC-1 ; i++) {
        if (!std::getline(globalFile, line)) {
                // Se atingirmos o final do arquivo antes de encontrar a linha desejada, saia
            std::cerr << "Erro: Não foi possível encontrar a linha desejada." << std::endl;
            return ; // Saia do programa com um código de erro
        }
    }
}

void DVM::JMPF(string label) {
    string line;

    if (M[S] == 0) {
        PC = stoi(label);
        globalFile.seekg(0);

        for (int i=0; i < PC-1 ; i++) {
            if (!std::getline(globalFile, line)) {
                    // Se atingirmos o final do arquivo antes de encontrar a linha desejada, saia
                std::cerr << "Erro: Não foi possível encontrar a linha desejada." << std::endl;
                return ; // Saia do programa com um código de erro
            }
        }
        // shift = (PC - 1) * averageLineLength;
        // globalFile.seekg(shift, std::ios::beg); 
    } else {
        PC = PC + 1;
    }
    S--;
}

void DVM::STR(string address) {
    M[stoi(address)] = M[S];
    S = S - 1;
    PC++;
}

void DVM::ALLOC(string current_address, string var_amount) {
    size_t start_index = stoi(current_address);
    size_t amount = stoi(var_amount);

    for(int i=0 ; i<amount ; i++) {
        S++;
        M[S] = M[start_index + i];
    }
    PC++;
}

void DVM::DALLOC(string current_address, string var_amount) {
    for(int i=stoi(var_amount)-1 ; i>=0 ; i--) {
        M[stoi(current_address) + i] = M[S];
        S--;
    }
    PC++;
}

void DVM::CALL(string address) {
    string line;

    S = S + 1;
    M[S] = PC + 1;

    PC = stoi(address);
    globalFile.seekg(0);

    for (int i=0; i < PC-1 ; i++) {
        if (!std::getline(globalFile, line)) {
                // Se atingirmos o final do arquivo antes de encontrar a linha desejada, saia
            std::cerr << "Erro: Não foi possível encontrar a linha desejada." << std::endl;
            return ; // Saia do programa com um código de erro
        }
    }
}

void DVM::RETURN() {
    string line;

    PC = M[S];
    S = S - 1;

    globalFile.seekg(0);

    for (int i=0; i < PC-1 ; i++) {
        if (!std::getline(globalFile, line)) {
            // Se atingirmos o final do arquivo antes de encontrar a linha desejada, saia
            std::cerr << "Erro: Não foi possível encontrar a linha desejada." << std::endl;
            return ; // Saia do programa com um código de erro
        }
    }

}

void DVM::RD() {
    int input;
    S++;
    cout << "valor: ";
    cin >> input;
    M[S] = input;
    PC++;
}

void DVM::PRN() {
    int output = M[S];
    cout << "\nimpresso: " << output << endl;
    PC++;
    S--;

}


