#ifndef expression_builder_h
#define expression_builder_h

#include <string>
#include "expr_token.h"
#include <vector>
#include "Expr_token.h"
#include "Token.h"



using namespace std;

class Expr_builder{
    public:
        static std::vector<Expr_token> expr_array;
        // static std::vector<string> integer_variables;
        // static std::vector<string> boolean_variables;
        // static std::vector<string> any_variables;

        void add_to_array(Token token);
        void add_to_array(Token token, Symbols symbol);
        void add_to_array(Token token, Symbols symbol, int address);
        Symbols infix_to_postfix();
        int precedence(string lexem, int position);
        bool isUnary(int i);
        void flush_expression();
};

#endif