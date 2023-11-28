#ifndef generate_h
#define generate_h

#include <fstream>
#include <iostream>
#include <string>
#include <array>
#include <vector>


class Instruction {
    public:
        static std::vector<Instruction> instructions;
        std::string label;
        std::string instruction;
        std::string attribute1;
        std::string attribute2;
        int flag;
};



std::string get_lpd_symbols(const std::string& token);
void generate_file();
void generate(std::string label, std::string instruction = "", std::string attribute1 = "", std::string attribute2 = "");


#endif