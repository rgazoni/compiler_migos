#include <fstream>
#include <iostream>

// Creating a node
class Node {
public:
  std::string lexem;
  std::string simbol;
  Node *next;
};
Node *head = NULL;

void unnecessary_characters_dump(char c, std::ifstream &file);

int main(int argc, char *argv[]) {

  std::ifstream file;
  file.open(argv[1]);
  if (!file.is_open()) {
    std::cout << "Error opening file" << std::endl;
    return 1;
  }
  char c;
  while (file.get(c)) {
    unnecessary_characters_dump(c, file);
  }
  file.close();
  return 0;
}

void unnecessary_characters_dump(char c, std::ifstream &file) {
  while ((c == '{' || c == ' ') && !file.eof()) {
    if (c == '{') {
      while (c != '}' && !file.eof()) {
        file.get(c);
      }
      file.get(c);
    }
    while (c == ' ' && !file.eof()) {
      file.get(c);
    }
  }
  if (!file.eof()) {
    std::cout << c;
  }
}

// Receive a alphanumeric character
void handle_reserved_words_and_identifiers(char c, std::ifstream &file) {
  std::string word;
  // Add the first character to the word string
  word += c;
  file.get(c);

  while (isalpha(c) || isdigit(c) || c == '_' && !file.eof()) {
    word += c;
    file.get(c);
  }

  if (word == "if" || word == "else" || word == "while" || word == "do" ||
      word == "break" || word == "continue" || word == "int" ||
      word == "double" || word == "float" || word == "return" ||
      word == "char" || word == "case" || word == "char" || word == "sizeof" ||
      word == "long" || word == "short" || word == "typedef" ||
      word == "switch" || word == "unsigned" || word == "void" ||
      word == "static" || word == "struct" || word == "goto" ||
      word == "auto" || word == "enum" || word == "extern" ||
      word == "register" || word == "signed") {
    std::cout << word << " is a reserved word" << std::endl;
  } else {
    std::cout << word << " is an identifier" << std::endl;
  }
}
