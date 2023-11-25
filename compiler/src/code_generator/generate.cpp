#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <functional>
#include <filesystem>

using namespace std;

string handle_add_case() {
    return "ADD";
}

string handle_sub_case() {
    return "SUB";
}

string handle_mult_case() {
    return "MULT";
}

string handle_divi_case() {
    return "DIVI";
}

string handle_and_case() {
    return "AND";
}

string handle_or_case() {
    return "OR";
}

string handle_less_than_case() {
    return "CME";
}

string handle_greater_than_case() {
    return "CMA";
}

string handle_equal_case() {
    return "CEQ";
}

string handle_not_equal_case() {
    return "CDIF";
}

string handle_less_equal_case() {
    return "CMEQ";
}

string handle_greater_equal_case() {
    return "CMAQ";
}

string get_lpd_symbols(const std::string& token) {
    std::unordered_map<std::string, std::function<std::string()>> cases = {
        {"+", handle_add_case},
        {"-", handle_sub_case},
        {"*", handle_mult_case},
        {"div", handle_divi_case},
        {"e", handle_and_case},
        {"ou", handle_or_case},
        {"<", handle_less_than_case},
        {">", handle_greater_than_case},
        {"=", handle_equal_case},
        {"!=", handle_not_equal_case},
        {"<=", handle_less_equal_case},
        {">=", handle_greater_equal_case}
        // Add more cases as needed
    };

    auto it = cases.find(token);
    if (it != cases.end()) {
        return it->second();  // Call the corresponding function
    } else {
        return "NULL";
    }
}

void generate(string label, string instruction, string attribute1, string attribute2){
    std::filesystem::path desktopPath = std::filesystem::current_path();
    std::string targetFolderName = "virtual_machine";
    std::filesystem::path targetFolderPath = desktopPath.parent_path() / targetFolderName;
    // std::filesystem::path outputPath = desktopPath / "virtual_machine";

    if (!std::filesystem::exists(targetFolderPath)) {
        std::filesystem::create_directory(targetFolderPath);
    }

    std::filesystem::path filePath = targetFolderPath / "byte_code.obj";

    int spaces_count;

    //open file in append mode
    std::ofstream outFile(filePath, std::ios_base::app);

    if(!outFile.is_open()){
        cerr << "Error opening file: " << filePath << endl;
        return;
    }     

    outFile << label;

    spaces_count = (sizeof(label)/8) - label.length();
    for(int i=0 ; i<spaces_count+1 ; i++){
        outFile << " ";
    }

    outFile << instruction;

    spaces_count = (sizeof(instruction)/4) - instruction.length();
    for(int i=0 ; i<spaces_count+1 ; i++){
        outFile << " ";
    }

    outFile << attribute1;

    spaces_count = (sizeof(attribute1)/8) - attribute1.length();
    for(int i=0 ; i<spaces_count+1 ; i++){
        outFile << " ";
    }

    
    outFile << attribute2;

    spaces_count = (sizeof(attribute2)/8) - attribute2.length();
    for(int i=0 ; i<spaces_count+1 ; i++){
        outFile << " ";
    }

    outFile << "\n";
    outFile.close();
}
