#include "Token.h"
#include "lexical_analyser.h"
#include "symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>

namespace {
    std::ifstream file;
    char *c = new char;
    int execution_line = 1;
    int execution_column = 1;
}

namespace Lexical {

    void open_file(char *argv[]) {
        file.open(argv[1]);
        if (!file.is_open()) {
            raiseError(Error::COULD_NOT_OPEN_FILE);
        }
        get_character_from_file();
    }
    
    void close_file() {
        file.close();
    }

    int get_execution_line() {
        return execution_line;
    }

    int get_execution_column() {
        return execution_column - 1;
    }

    Token* get_token() { 
        if (!file.eof()) {
            unnecessary_characters_dump();
            if (!file.eof()) {
                if (isdigit(*c)) {
                    return handle_digit();
                } else if (isalpha(*c)) {
                    return handle_reserved_words_and_identifiers();
                } else if(*c == ':'){
                    return handle_assignment();
                } else if (*c == '+' || *c == '-' || *c == '*') {
                    return handle_aritmethic_operator();
                } else if (*c == '!' || *c == '<' || *c == '>' || *c == '=') {
                    return handle_relational_operator();
                } else if (*c == ';' || *c == ',' || *c == '(' || *c == ')' || *c == '.') {
                    return handle_punctuation();
                } else {
                    raiseError(Error::TOKEN_NOT_VALID);
                }
            }
        }
        return NULL;
    }
}

void get_character_from_file() {
    file.get(*c);
    execution_column++;
}

void unnecessary_characters_dump() {

    while ((*c == '{' || *c == ' ' || (int)*c == 13 || (int)*c == 10 || (int)*c == 9)
            && !file.eof()) {
        if (*c == '{') {
            while (*c != '}' && !file.eof()) {
                get_character_from_file();
            }
            get_character_from_file();
        }
        while ((*c == ' ' || (int)*c == 13 || (int)*c == 10 || (int)*c == 9)
            && !file.eof()) {

            if ((int)*c == 10) {
                execution_line++;
                execution_column = 1;
            }

            get_character_from_file();
        }
    }
}

// Receive a alphanumeric character
Token* handle_reserved_words_and_identifiers() {
    std::string word;
    // Add the first character to the word string
    word += c;
    get_character_from_file();
    // Form lexem
    while (isalpha(*c) || isdigit(*c) || *c == '_' && !file.eof()) {
        word += *c;
        get_character_from_file();
    }
    Token *token = new_node(word, Symbols::EMPTY);

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
    return token;
  }

Token* handle_digit() {
    std::string word;
    word = *c;
    get_character_from_file();
    while (isdigit(*c) && !file.eof()) {
        word += c;
        get_character_from_file();
    }
    Token *token = new_node(word, Symbols::SNUMERO);
    return token;
}

Token* handle_aritmethic_operator() {
    std::string word;
    word = *c;
    get_character_from_file();
    Token *token = new_node(word, Symbols::EMPTY);

    if (token->lexem == "+") {
        token->symbol = Symbols::SMAIOR;
    } else if (token->lexem == "-") {
        token->symbol = Symbols::SMENOS;
    } else if (token->lexem == "*") {
        token->symbol = Symbols::SMULT;
    }
    return token;
}

Token* handle_relational_operator() {
    std::string word;
    word = *c;
    Token *token = new_node(word, Symbols::EMPTY);
    get_character_from_file();

    if (word == ">") {
        if (*c == '=') {
            token->symbol = Symbols::SMAIORIG;
            word += c;
            token->lexem = word;
            get_character_from_file();
        } else
            token->symbol = Symbols::SMAIOR;
    } else if (word == "<") {
        if (*c == '=') {
            token->symbol = Symbols::SMENORIG;
            word += c;
            token->lexem = word;
            get_character_from_file();
        } else
            token->symbol = Symbols::SMENOR;
    } else if (word == "!") {
        if (*c == '=') {
            token->symbol = Symbols::SDIF;
            word += c;
            token->lexem = word;
            get_character_from_file();
        } else{
            token->symbol = Symbols::SERRO;
        }
    } else if (word == "=") {
        token->symbol = Symbols::SIG;
    }

    return token;
}

Token* handle_punctuation() {
    std::string word;
    word = *c;
    get_character_from_file();
    Token *token = new_node(word, Symbols::EMPTY);

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

    return token;
}

Token* handle_assignment() {
    std::string word;
    word = *c;
    get_character_from_file();
    if (*c == '=') { 
        word += *c;
        Token *token = new_node(word, Symbols::SATRIBUICAO);
        get_character_from_file();
        return token;
    } else {
        Token *token = new_node(word, Symbols::SDOISPONTOS);
        return token;
    }   
}

