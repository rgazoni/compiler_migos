#include "symbols.h"
#include <fstream>
#include <iostream>

#include <string>
#ifndef linked_list_h
#define linked_list_h

class Node {
public:
  Symbols symbol;
  std::string lexem;
  Node *next;
};

extern Node *head;

Node *new_node(std::string lexem, Symbols symbol);
void insert_node(Node *node);
void print_linked_list();

#endif
