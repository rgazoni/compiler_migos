#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int digitsAmount(int number) {
    std::string numberStr = std::to_string(number);
    return numberStr.length();
}


void generate(int label, string instruction, int attribute1, int attribute2){
    const char* filename = "assembly.obj";
    int spaces_count;

    //open file in append mode
    std::ofstream outputFile(filename, std::ios_base::app);

    if(!outputFile.is_open()){
        cerr << "Error opening file: " << filename << endl;
        return;
    }     

    if(label == -1)
        outputFile << "  ";
    else
        outputFile << label;

    spaces_count = sizeof(label) - digitsAmount(label);
    for(int i=0 ; i<spaces_count+1 ; i++){
        outputFile << " ";
    }

    if(instruction == "")
        outputFile << "";
    else
        outputFile << instruction;

    spaces_count = (sizeof(instruction)/4) - instruction.length();
    for(int i=0 ; i<spaces_count+1 ; i++){
        outputFile << " ";
    }

    if(attribute1 == -1)
        outputFile << "     ";
    else
        outputFile << attribute1;

    spaces_count = sizeof(attribute1) - digitsAmount(attribute1);
    for(int i=0 ; i<spaces_count+1 ; i++){
        outputFile << " ";
    }

    if(attribute2 == -1)
        outputFile << "     ";
    else
        outputFile << attribute2;

    spaces_count = sizeof(attribute2) - digitsAmount(attribute2);
    for(int i=0 ; i<spaces_count+1 ; i++){
        outputFile << " ";
    }

    outputFile << "\n";

    // cout << sizeof(label) << sizeof(instruction) << sizeof(attribute1) << sizeof(attribute2) << endl;

    outputFile.close();
}
