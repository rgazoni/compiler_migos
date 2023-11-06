#ifndef expression_builder_h
#define expression_builder_h

#include <string>
#include "expr_token.h"
#include <vector>

using namespace std;

class Expr_builder{
    public:
        static std::vector<Expr_token> expr_array;
        void add_to_array(Expr_token token);
        std::vector<Expr_token> infix_to_postfix();
        int precedence(string lexem, int position);
        bool isUnary(int i);
};

#endif