#ifndef semantic_analyzer
#define semantic_analyzer

#include <iostream>
#include <stack>
#include <string>
#include <vector>

#include "Expr_token.h"

// Enumeração para representar tipos
class Semantic_analyzer{
    public:
        Type validateExpression(std::vector<Expr_token>& expression);
};

#endif
