#include <fstream>
#include <iostream>

//--------- Dealing with Linked List ---------
class Node {
public:
  std::string lexem;
  std::string symbol;
  Node *next;
};
Node *head = NULL;

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
// -------------------------------------------

void unnecessary_characters_dump(char c, std::ifstream &file);
void handle_reserved_words_and_identifiers(char c, std::ifstream &file);

int main(int argc, char *argv[]) {

  std::ifstream file;
  file.open(argv[1]);
  if (!file.is_open()) {
    std::cout << "Error opening file" << std::endl;
    return 1;
  }
  char c;
  file.get(c);
  while (!file.eof()) {
    unnecessary_characters_dump(c, file);
    if (!file.eof()) {
      if (isalpha(c)) {
        handle_reserved_words_and_identifiers(c, file);
      }
      file.get(c);
    }
  }
  file.close();
  printf("\n");
  print_linked_list();
  return 0;
}

void unnecessary_characters_dump(char c, std::ifstream &file) {
  while ((c == '{' || c == ' ') && !file.eof()) {
    if (c == '{') {
      while (c != '}' && !file.eof()) {
        file.get(c);
      }
      file.get(c);
      while (c == ' ' && !file.eof()) {
        file.get(c);
      }
    }
  }
}

// Receive a alphanumeric character
void handle_reserved_words_and_identifiers(char c, std::ifstream &file) {
  std::string word;
  // Add the first character to the word string
  word += c;
  file.get(c);
  // Form lexem
  while (isalpha(c) || isdigit(c) || c == '_' && !file.eof()) {
    word += c;
    file.get(c);
  }
  Node *token = new Node();
  token->lexem = word;

  if (word == "programa") {
    token->symbol = "sprograma";
  } else if (word == "se") {
    token->symbol = "sse";
  } else if (word == "entao") {
    token->symbol = "sentao";
  } else if (word == "senao") {
    token->symbol = "ssenao";
  } else if (word == "enquanto") {
    token->symbol = "senquanto";
  } else if (word == "faca") {
    token->symbol = "sfaca";
  } else if (word == "inicio") {
    token->symbol = "sinicio";
  } else if (word == "fim") {
    token->symbol = "sfim";
  } else if (word == "escreva") {
    token->symbol = "sescreva";
  } else if (word == "leia") {
    token->symbol = "sleia";
  } else if (word == "var") {
    token->symbol = "svar";
  } else if (word == "inteiro") {
    token->symbol = "sinteiro";
  } else if (word == "booleano") {
    token->symbol = "sbooleano";
  } else if (word == "verdadeiro") {
    token->symbol = "sverdadeiro";
  } else if (word == "falso") {
    token->symbol = "sfalso";
  } else if (word == "procedimento") {
    token->symbol = "sprocedimento";
  } else if (word == "funcao") {
    token->symbol = "sfuncao";
  } else if (word == "div") {
    token->symbol = "sdiv";
  } else if (word == "e") {
    token->symbol = "se";
  } else if (word == "ou") {
    token->symbol = "sou";
  } else if (word == "nao") {
    token->symbol = "snao";
  } else {
    token->symbol = "sidentificador";
  }

  insert_node(token);
}
