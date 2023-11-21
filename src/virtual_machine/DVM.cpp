#include "DVM.h"
#include <iostream>
#include <cctype>
#include <string>
#include <stack>


using namespace std;

int DVM::S = -1;
int DVM::PC = 0;
std::stack<int> DVM::M = {};

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
        cout << "command: " << command << endl;

        // std::cout << "command1: " << command << std::endl;
        if(isDigit(command) || command == "NULL")
            iss >> command;

        // std::cout << "command2: " << command << std::endl;

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
        } else if (command == "ALLOC") {
            string address;
            string var_count;
            iss >> address;
            if(iss >> var_count)
                ALLOC(address, var_count);
        }
    
        PC++;
        displayState();
    }

    file.close();
}


// // Exibir estado atual
// void DVM::displayState() {
//     std::cout << "Stack: ";
//     for (int i = 0; i < M.size() ; i++) {
//         std::cout << M[i] << " | ";
//     }
//     std::cout << "\n" << "PC: " << PC << "\n";
// }

// // Carregar constante
// void DVM::LDC(string k) {
//     S++;
//     M[S] = stoi(k);
// }

// // Carregar valor
// void DVM::LDV(string n) {
//     S++;
//     M[S] = M[stoi(n)];
// }

// // Somar
// void DVM::ADD() {
//     M[S - 1] += M[S];
//     S--;
// }

// // Subtrair
// void DVM::SUB() {
//     M[S - 1] -= M[S];
//     S--;
// }

// // Multiplicar
// void DVM::MULT() {
//     M[S - 1] *= M[S];
//     S--;
// }

// // Dividir
// void DVM::DIVI() {
//     M[S - 1] /= M[S];
//     S--;
// }

// // Inverter sinal
// void DVM::INV() {
//     M[S] = -M[S];
// }

// // Conjunção
// void DVM::AND() {
//     if (M[S - 1] == 1 && M[S] == 1)
//         M[S - 1] = 1;
//     else
//         M[S - 1] = 0;
//     S--;
// }

// // Disjunção
// void DVM::OR() {
//     if (M[S - 1] == 1 || M[S] == 1)
//         M[S - 1] = 1;
//     else
//         M[S - 1] = 0;
//     S--;
// }

// // Negação
// void DVM::NEG() {
//     M[S] = 1 - M[S];
// }

// // Comparar menor
// void DVM::CME() {
//     if (M[S - 1] < M[S])
//         M[S - 1] = 1;
//     else
//         M[S - 1] = 0;
//     S--;
// }

// // Comparar maior
// void DVM::CMA() {
//     if (M[S - 1] > M[S])
//         M[S - 1] = 1;
//     else
//         M[S - 1] = 0;
//     S--;
// }

// // Comparar igual
// void DVM::CEQ() {
//     if (M[S - 1] == M[S])
//         M[S - 1] = 1;
//     else
//         M[S - 1] = 0;
//     S--;
// }

// // Comparar desigual
// void DVM::CDIF() {
//     if (M[S - 1] != M[S])
//         M[S - 1] = 1;
//     else
//         M[S - 1] = 0;
//     S--;
// }

// // Comparar menor ou igual
// void DVM::CMEQ() {
//     if (M[S - 1] <= M[S])
//         M[S - 1] = 1;
//     else
//         M[S - 1] = 0;
//     S--;
// }

// // Comparar maior ou igual
// void DVM::CMAQ() {
//     if (M[S - 1] >= M[S])
//         M[S - 1] = 1;
//     else
//         M[S - 1] = 0;
//     S--;
// }

// void DVM::JMP(string label) {
//     PC = stoi(label);
// }

// void DVM::JMPF(string label) {
//     if (M[S] == 0) {
//         PC = stoi(label);
//     } else {
//         PC = PC + 1;
//     }

//     S--;
// }

// void DVM::ALLOC(string var_count) {
//     for(int i=0 ; i<=stoi(var_count)-1 ; i++) {
//         //acessar tabela de tipos para colocar o respectivo endereço
//         S++;
//         M[S] = M[current_available_address + i];
//         current_available_address = current_available_address + stoi(var_count);
//     }
//     cout << "alloc stack: " << S << endl;
// }

// void DVM::ALLOC(string current_available_address, string var_count) {
//     int count = stoi(var_count);
//     cout << "var_count: " << count << endl;

//     // Resize the vector if necessary
//     M.resize(stoi(current_available_address) + count);

//     for (int k = 0; k < count; k++) {
//         // Access table of types to put the respective address
//         int index = stoi(current_available_address) + k;
//         cout << "Index: " << index << ", M[" << index << "]: " << M[index] << endl;

//         S++;
//         M.push_back(M[index]);
//     }

//     cout << "addresS:::::::::: " << stoi(current_available_address) << endl;
// }

// void DVM::DALLOC(string var_count) {
//     for(int i=stoi(var_count)-1 ; i>=0 ; i--) {
//         //acessar tabela de tipos para colocar o respectivo endereço
//         M[S + i] = M[S];
//         S--;
//     }
//     cout << "dalloc stack: " << S << endl;

// }

void DVM::displayState() {
    std::cout << "Stack: ";
    std::stack<int> tempStack = M;

    while (!tempStack.empty()) {
        std::cout << tempStack.top() << " | ";
        tempStack.pop();
    }

    std::cout << "\nPC: " << PC << "\n";
}

void DVM::LDC(string k) {
    S++;
    M.push(stoi(k));
}

void DVM::LDV(string n) {
    int index = stoi(n);
    S++;
    M.push(M.top());
}

void DVM::ADD() {
    int operand1 = M.top();
    M.pop();
    int operand2 = M.top();
    M.pop();
    M.push(operand1 + operand2);
    S--;
}

void DVM::SUB() {
    int operand1 = M.top();
    M.pop();
    int operand2 = M.top();
    M.pop();
    M.push(operand1 - operand2);
    S--;
}

void DVM::MULT() {
    int operand1 = M.top();
    M.pop();
    int operand2 = M.top();
    M.pop();
    M.push(operand1 * operand2);
    S--;
}

void DVM::DIVI() {
    int operand1 = M.top();
    M.pop();
    int operand2 = M.top();
    M.pop();
    M.push(operand1 / operand2);
    S--;
}

void DVM::INV() {
    int value = M.top();
    M.pop();
    M.push(-value);
}

void DVM::AND() {
    int operand1 = M.top();
    M.pop();
    int operand2 = M.top();
    M.pop();
    M.push((operand1 == 1 && operand2 == 1) ? 1 : 0);
    S--;
}

void DVM::OR() {
    int operand1 = M.top();
    M.pop();
    int operand2 = M.top();
    M.pop();
    M.push((operand1 == 1 || operand2 == 1) ? 1 : 0);
    S--;
}

void DVM::NEG() {
    int value = M.top();
    M.pop();
    M.push(1 - value);
}

void DVM::CME() {
    int operand1 = M.top();
    M.pop();
    int operand2 = M.top();
    M.pop();
    M.push((operand1 < operand2) ? 1 : 0);
    S--;
}

void DVM::CMA() {
    int operand1 = M.top();
    M.pop();
    int operand2 = M.top();
    M.pop();
    M.push((operand1 > operand2) ? 1 : 0);
    S--;
}

void DVM::CEQ() {
    int operand1 = M.top();
    M.pop();
    int operand2 = M.top();
    M.pop();
    M.push((operand1 == operand2) ? 1 : 0);
    S--;
}

void DVM::CDIF() {
    int operand1 = M.top();
    M.pop();
    int operand2 = M.top();
    M.pop();
    M.push((operand1 != operand2) ? 1 : 0);
    S--;
}

void DVM::CMEQ() {
    int operand1 = M.top();
    M.pop();
    int operand2 = M.top();
    M.pop();
    M.push((operand1 <= operand2) ? 1 : 0);
    S--;
}

void DVM::CMAQ() {
    int operand1 = M.top();
    M.pop();
    int operand2 = M.top();
    M.pop();
    M.push((operand1 >= operand2) ? 1 : 0);
    S--;
}

void DVM::JMP(string label) {
    PC = stoi(label);
}

void DVM::JMPF(string label) {
    if (M.top() == 0) {
        PC = stoi(label);
    } else {
        PC = PC + 1;
    }

    M.pop();
    S--;
}

void DVM::ALLOC(string current_available_address, string var_count) {
    int count = stoi(var_count);
    cout << "var_count: " << count << endl;

    // Get the current stack size
    int currentStackSize = M.size();

    for (int k = 0; k < count; k++) {
        // Access table of types to put the respective address

        S++;
        if (!M.empty()) {
            M.push(M.top());  
        } else
            M.push(0);  
        
    }

    cout << "addresS:::::::::: " << stoi(current_available_address) << endl;
}

void DVM::DALLOC(string var_count) {
    for (int i = stoi(var_count) - 1; i >= 0; i--) {
        //acessar tabela de tipos para colocar o respectivo endereço
        M.push(M.top());
        S--;
    }
    cout << "dalloc stack: " << S << endl;
}
