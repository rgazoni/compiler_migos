#include "linked_list.h"
#include <fstream>
#include <iostream>

Node *head = NULL;

Node *new_node(std::string lexem, std::string symbol) {
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

void print_linked_list() {
  Node *temp = head;
  while (temp != NULL) {
    std::cout << temp->lexem << " " << temp->symbol << std::endl;
    temp = temp->next;
  }
}
