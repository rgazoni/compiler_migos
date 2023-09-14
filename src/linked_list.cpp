#include "linked_list.h"
#include "symbols.h"
#include <fstream>
#include <iostream>

Node *head = NULL;

Node *new_node(std::string lexem, Symbols symbol) {
  Node *node = new Node();
  node->lexem = lexem;
  node->symbol = symbol;
  node->next = NULL;
  return node;
}

void insert_node(Node *node) {
  if (head == NULL) {
    head = node;
  } else {
    Node *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = node;
  }
}

//https://cplusplus.com/forum/general/263696/
void print_linked_list() {
  Node *temp = head;
  std::cout << "------------------ PRINT LINKED LIST ---------------------" << std::endl;
  std::cout << "\tLexem  \t\t\t\t  Symbol" << std::endl;
  while (temp != NULL) {
    std::cout << "\t" << temp->lexem << "\t\t\t\t" << temp->symbol << std::endl;
    temp = temp->next;
  }
}
