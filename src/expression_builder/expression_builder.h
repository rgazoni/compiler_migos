#ifndef expression_builder_h
#define expression_builder_h

#include <string>
#include "expr_token.h"
#include <vector>

using namespace std;

class Expr_builder{
    public:
        std::vector<Expr_token> expr_array;
        void add_to_array(Expr_token token);
        std::vector<Expr_token> infix_to_postfix();
        // std::vector<Expr_token> Expr_builder::handle_unary_operators();
        int precedence(string lexem, int position);
        bool isUnary(int i);
};

#endif