#ifndef generate_h
#define generate_h

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

std::string get_lpd_symbols(const std::string& token);
void generate(string label, string instruction = "", string attribute1 = "", string attribute2 = "");


#endif