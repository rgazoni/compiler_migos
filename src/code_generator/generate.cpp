#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int digitsAmount(string number) {
    // std::string numberStr = to_string(stoi(number));
    return number.length();
}


void generate(string label, string instruction, string attribute1, string attribute2){
    const char* filename = "assembly.obj";
    int spaces_count;

    //open file in append mode
    std::ofstream outputFile(filename, std::ios_base::app);

    if(!outputFile.is_open()){
        cerr << "Error opening file: " << filename << endl;
        return;
    }     

    outputFile << label;

    spaces_count = (sizeof(label)/8) - digitsAmount(label);
    for(int i=0 ; i<spaces_count+1 ; i++){
        outputFile << " ";
    }

    outputFile << instruction;

    spaces_count = (sizeof(instruction)/4) - instruction.length();
    for(int i=0 ; i<spaces_count+1 ; i++){
        outputFile << " ";
    }

    outputFile << attribute1;

    spaces_count = (sizeof(attribute1)/8) - digitsAmount(attribute1);
    for(int i=0 ; i<spaces_count+1 ; i++){
        outputFile << " ";
    }

    
    outputFile << attribute2;

    spaces_count = (sizeof(attribute2)/8) - digitsAmount(attribute2);
    for(int i=0 ; i<spaces_count+1 ; i++){
        outputFile << " ";
    }

    outputFile << "\n";

    // cout << sizeof(label) << sizeof(instruction) << sizeof(attribute1) << sizeof(attribute2) << endl;

    outputFile.close();
}
