#include "symbols.h"
#include <fstream>
#include <iostream>
#include <string>

#ifndef Token_h
#define Token_h

class Token {
public:
  Symbols symbol;
  std::string lexem;
};

Token *new_node(std::string lexem, Symbols symbol);

#endif
