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
        Expr_token(std::string x, Type y){
            lexem = x;
            type = y;
        }
};

#endif
