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
        Type type;
        int address;
        Expr_token(std::string x, Type y, int z = 0){
            lexem = x;
            type = y;
            address = z;
        }
};

#endif
