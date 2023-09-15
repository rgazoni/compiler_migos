#include "linked_list.h"
#include "symbol_table.h"
#include <fstream>
#include <iostream>

void unnecessary_characters_dump(char *c, std::ifstream &file);
void handle_reserved_words_and_identifiers(char *c, std::ifstream &file);
void handle_digit(char *c, std::ifstream &file);
void handle_aritmethic_operator(char *c, std::ifstream &file);
void handle_assignment(char *c, std::ifstream &file);
void handle_relational_operator(char *c, std::ifstream &file);
void handle_ponctuation(char *c, std::ifstream &file);
Symbol_table symbol_table;
Record record = Record();

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
    while ((*c == '{' || *c == ' ') && !file.eof()) {
        if (*c == '{') {
            while (*c != '}' && !file.eof()) {
                file.get(*c);
            }
            file.get(*c);
        }
        while (*c == ' ' && !file.eof()) {
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
    Node *token = new_node(word, "");

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
        record.setLexem(word);
        record.setType(token->symbol);
        symbol_table.insert_record(&record);
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
    Node *token = new_node(word, "snumero");
    insert_node(token);
}

void handle_aritmethic_operator(char *c, std::ifstream &file) {
    std::string word;
    word = *c;
    file.get(*c);
    Node *token = new_node(word, "");

    if (token->lexem == "+") {
        token->symbol = "smais";
    } else if (token->lexem == "-") {
        token->symbol = "smenos";
    } else if (token->lexem == "*") {
        token->symbol = "smult";
    }

    insert_node(token);
}

void handle_relational_operator(char *c, std::ifstream &file) {
    std::string word;
    word = *c;
    Node *token = new_node(word, "");
    file.get(*c);

    if (word == ">") {
        if (*c == '=') {
            token->symbol = "smaiorig";
            word += c;
            token->lexem = word;
            file.get(*c);
        } else
            token->symbol = "smaior";
    } else if (word == "<") {
        if (*c == '=') {
            token->symbol = "smenorig";
            word += c;
            token->lexem = word;
            file.get(*c);
        } else
            token->symbol = "smenor";
    } else if (word == "!") {
        if (*c == '=') {
            token->symbol = "sdif";
            word += c;
            token->lexem = word;
            file.get(*c);
        } else{
            //FALAR COM FREITAS
            //exit(1);
        }
    } else if (word == "=") {
        token->symbol = "sig";
    }

    insert_node(token);
}

void handle_ponctuation(char *c, std::ifstream &file) {
    std::string word;
    word = *c;
    file.get(*c);
    Node *token = new_node(word, "");

    if (word == ";") {
        token->symbol = "sponto_virgula";
    } else if (word == ",") {
        token->symbol = "svirgula";
    } else if (word == "(") {
        token->symbol = "sabre_parenteses";
    } else if (word == ")") {
        token->symbol = "sfecha_parenteses";
    } else if (word == ".") {
        token->symbol = "sponto";
    }

    insert_node(token);
}

void handle_assignment(char *c, std::ifstream &file) {
    std::string word;
    word = *c;
    file.get(*c);
    if (*c == '=') { 
        word += *c;
        Node *token = new_node(word, "satribuicao");
        insert_node(token);
        file.get(*c);
    } else {
        Node *token = new_node(word, "sdoispontos");
        insert_node(token);
    }   
}
