#include "linked_list.h"
#include "symbols.h"
#include <fstream>
#include <iostream>

void unnecessary_characters_dump(char *c, std::ifstream &file);
void handle_reserved_words_and_identifiers(char *c, std::ifstream &file);
void handle_digit(char *c, std::ifstream &file);
void handle_aritmethic_operator(char *c, std::ifstream &file);
void handle_assignment(char *c, std::ifstream &file);
void handle_relational_operator(char *c, std::ifstream &file);
void handle_ponctuation(char *c, std::ifstream &file);

int main(int argc, char *argv[]) { 
    std::ifstream file;
    file.open(argv[1]);
    if (!file.is_open()) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }
    char *c = new char;
    file.get(*c);
    while (!file.eof()) {
        unnecessary_characters_dump(c, file);
        if (!file.eof()) {
            if (isdigit(*c)) {
                handle_digit(c, file);
            } else if (isalpha(*c)) {
                handle_reserved_words_and_identifiers(c, file);
            } else if(*c == ':'){
                handle_assignment(c, file);
            } else if (*c == '+' || *c == '-' || *c == '*') {
                handle_aritmethic_operator(c, file);
            } else if (*c == '!' || *c == '<' || *c == '>' || *c == '=') {
                handle_relational_operator(c, file);
            } else if (*c == ';' || *c == ',' || *c == '(' || *c == ')' || *c == '.') {
                handle_ponctuation(c, file);
            } else {
                Node* token = new_node(c, Symbols::SERRO);
                insert_node(token);
                file.get(*c);
            }
        }
    }

    file.close();
    printf("\n");
    print_linked_list();
    return 0;
}

void unnecessary_characters_dump(char *c, std::ifstream &file) {
    while ((*c == '{' || *c == ' ' || (int)*c == 13 || (int)*c == 10 || (int)*c == 9)
            && !file.eof()) {
        if (*c == '{') {
            while (*c != '}' && !file.eof()) {
                file.get(*c);
            }
            file.get(*c);
        }
        while ((*c == ' ' || (int)*c == 13 || (int)*c == 10 || (int)*c == 9)
            && !file.eof()) {
            file.get(*c);
        }
    }
}

// Receive a alphanumeric character
void handle_reserved_words_and_identifiers(char *c, std::ifstream &file) {    //
    std::string word;
    // Add the first character to the word string
    word += c;
    file.get(*c);
    // Form lexem
    while (isalpha(*c) || isdigit(*c) || *c == '_' && !file.eof()) {
        word += *c;
        file.get(*c);
    }
    Node *token = new_node(word, Symbols::EMPTY);

    if (word == "programa") {
        token->symbol = Symbols::SPROGRAMA;
    } else if (word == "se") {
        token->symbol = Symbols::SSE;
    } else if (word == "entao") {
        token->symbol = Symbols::SENTAO;
    } else if (word == "senao") {
        token->symbol = Symbols::SSENAO;
    } else if (word == "enquanto") {
        token->symbol = Symbols::SENQUANTO;
    } else if (word == "faca") {
        token->symbol = Symbols::SFACA;
    } else if (word == "inicio") {
        token->symbol = Symbols::SINICIO;
    } else if (word == "fim") {
        token->symbol = Symbols::SFIM;
    } else if (word == "escreva") {
        token->symbol = Symbols::SESCREVA;
    } else if (word == "leia") {
        token->symbol = Symbols::SLEIA;
    } else if (word == "var") {
        token->symbol = Symbols::SVAR;
    } else if (word == "inteiro") {
        token->symbol = Symbols::SINTEIRO;
    } else if (word == "booleano") {
        token->symbol = Symbols::SBOOLEANO;
    } else if (word == "verdadeiro") {
        token->symbol = Symbols::SVERDADEIRO;
    } else if (word == "falso") {
        token->symbol = Symbols::SFALSO;
    } else if (word == "procedimento") {
        token->symbol = Symbols::SPROCEDIMENTO;
    } else if (word == "funcao") {
        token->symbol = Symbols::SFUNCAO;
    } else if (word == "div") {
        token->symbol = Symbols::SDIV;
    } else if (word == "e") {
        token->symbol = Symbols::SE;
    } else if (word == "ou") {
        token->symbol = Symbols::SOU;
    } else if (word == "nao") {
        token->symbol = Symbols::SNAO;
    } else {
        token->symbol = Symbols::SIDENTIFICADOR;
    }
    insert_node(token); 
  }

void handle_digit(char *c, std::ifstream &file) {
    std::string word;
    word = *c;
    file.get(*c);
    while (isdigit(*c) && !file.eof()) {
        word += c;
        file.get(*c);
    }
    Node *token = new_node(word, Symbols::SNUMERO);
    insert_node(token);
}

void handle_aritmethic_operator(char *c, std::ifstream &file) {
    std::string word;
    word = *c;
    file.get(*c);
    Node *token = new_node(word, Symbols::EMPTY);

    if (token->lexem == "+") {
        token->symbol = Symbols::SMAIOR;
    } else if (token->lexem == "-") {
        token->symbol = Symbols::SMENOS;
    } else if (token->lexem == "*") {
        token->symbol = Symbols::SMULT;
    }

    insert_node(token);
}

void handle_relational_operator(char *c, std::ifstream &file) {
    std::string word;
    word = *c;
    Node *token = new_node(word, Symbols::EMPTY);
    file.get(*c);

    if (word == ">") {
        if (*c == '=') {
            token->symbol = Symbols::SMAIORIG;
            word += c;
            token->lexem = word;
            file.get(*c);
        } else
            token->symbol = Symbols::SMAIOR;
    } else if (word == "<") {
        if (*c == '=') {
            token->symbol = Symbols::SMENORIG;
            word += c;
            token->lexem = word;
            file.get(*c);
        } else
            token->symbol = Symbols::SMENOR;
    } else if (word == "!") {
        if (*c == '=') {
            token->symbol = Symbols::SDIF;
            word += c;
            token->lexem = word;
            file.get(*c);
        } else{
            token->symbol = Symbols::SERRO;
        }
    } else if (word == "=") {
        token->symbol = Symbols::SIG;
    }

    insert_node(token);
}

void handle_ponctuation(char *c, std::ifstream &file) {
    std::string word;
    word = *c;
    file.get(*c);
    Node *token = new_node(word, Symbols::EMPTY);

    if (word == ";") {
        token->symbol = Symbols::SPONTO_VIRGULA;
    } else if (word == ",") {
        token->symbol = Symbols::SVIRGULA;
    } else if (word == "(") {
        token->symbol = Symbols::SABRE_PARENTESES;
    } else if (word == ")") {
        token->symbol = Symbols::SFECHA_PARENTESES;
    } else if (word == ".") {
        token->symbol = Symbols::SPONTO;
    }

    insert_node(token);
}

void handle_assignment(char *c, std::ifstream &file) {
    std::string word;
    word = *c;
    file.get(*c);
    if (*c == '=') { 
        word += *c;
        Node *token = new_node(word, Symbols::SATRIBUICAO);
        insert_node(token);
        file.get(*c);
    } else {
        Node *token = new_node(word, Symbols::SDOISPONTOS);
        insert_node(token);
    }   
}
