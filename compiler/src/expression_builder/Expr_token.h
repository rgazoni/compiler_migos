#ifndef Expr_token_h
#define Expr_token_h

#include <fstream>
#include <iostream>
#include <string>

#include "symbols.h"
#include "types_table.h"

struct Expr_token {
    public:
        std::string lexem;
        Symbols symbol;
        int address;
        Expr_token(std::string x, Symbols y, int z = 0){
            lexem = x;
            symbol = y;
            address = z;
        }
};

#endif
