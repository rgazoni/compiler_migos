#include <fstream>
#include <iostream>

#include <string>
#ifndef linked_list_h
#define linked_list_h

class Node {
public:
  std::string symbol;
  std::string lexem;
  Node *next;
};

extern Node *head;

Node *new_node(std::string lexem, std::string symbol);
void insert_node(Node *node);
void print_linked_list();

#endif
