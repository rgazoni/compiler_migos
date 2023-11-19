#ifndef expression_builder_h
#define expression_builder_h

#include <string>
#include "expr_token.h"
#include <vector>
#include "Expr_token.h"


using namespace std;

class Expr_builder{
    public:
        static std::vector<Expr_token> expr_array;
        static std::vector<string> integer_variables;
        static std::vector<string> boolean_variables;
        static std::vector<string> any_variables;

        void add_to_array(Expr_token token);
        Type infix_to_postfix();
        int precedence(string lexem, int position);
        bool isUnary(int i);
        void flush_expression();
};

#endif