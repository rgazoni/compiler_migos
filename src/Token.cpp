#include "Token.h"

Token *new_node(std::string lexem, Symbols symbol) {
  Token *node = new Token();
  node->lexem = lexem;
  node->symbol = symbol;
  return node;
}

