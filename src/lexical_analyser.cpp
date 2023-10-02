#include "Token.h"
#include "lexical_analyser.h"
#include "symbols.h"
#include "./error/Errors.h"
#include <fstream>
#include <iostream>

//Defining static variables
Token* Lexical::current_token = new Token();
int Lexical::execution_line = 1;
int Lexical::execution_column = 0;
char* Lexical::c = new char;
std::ifstream Lexical::file;

void Lexical::open_file(char *argv[]) {
    file.open(argv[1]);
    if (!file.is_open()) {
        raiseError(Error::COULD_NOT_OPEN_FILE);
    }
    get_character_from_file();
}

void Lexical::close_file() {
    file.close();
}

int Lexical::get_execution_line() {
    return execution_line;
}

int Lexical::get_execution_column() {
    return execution_column;
}

Token Lexical::get_current_token() {
    return *current_token;
}

void Lexical::next_token() { 
    if (!file.eof()) {
        unnecessary_characters_dump();
        if (!file.eof()) {
            if (isdigit(*c)) {
                handle_digit();
            } else if (isalpha(*c)) {
                handle_reserved_words_and_identifiers();
            } else if(*c == ':'){
                handle_assignment();
            } else if (*c == '+' || *c == '-' || *c == '*') {
                handle_aritmethic_operator();
            } else if (*c == '!' || *c == '<' || *c == '>' || *c == '=') {
                handle_relational_operator();
            } else if (*c == ';' || *c == ',' || *c == '(' || *c == ')' || *c == '.') {
                handle_punctuation();
            } else {
                raiseError(Error::TOKEN_NOT_VALID);
            }
        }
    }

    if (file.eof()) {
        current_token->symbol = Symbols::END_OF_FILE;
        current_token->lexem = "";
    }

}

void Lexical::get_character_from_file() {
    file.get(*c);
    execution_column++;
}

void Lexical::unnecessary_characters_dump() {

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

void Lexical::handle_reserved_words_and_identifiers() {
    std::string word;
    // Add the first character to the word string
    word += c;
    get_character_from_file();
    // Form lexem
    while (isalpha(*c) || isdigit(*c) || *c == '_' && !file.eof()) {
        word += *c;
        get_character_from_file();
    }

    current_token->lexem = word;

    if (word == "programa") {
        current_token->symbol = Symbols::SPROGRAMA;
    } else if (word == "se") {
        current_token->symbol = Symbols::SSE;
    } else if (word == "entao") {
        current_token->symbol = Symbols::SENTAO;
    } else if (word == "senao") {
        current_token->symbol = Symbols::SSENAO;
    } else if (word == "enquanto") {
        current_token->symbol = Symbols::SENQUANTO;
    } else if (word == "faca") {
        current_token->symbol = Symbols::SFACA;
    } else if (word == "inicio") {
        current_token->symbol = Symbols::SINICIO;
    } else if (word == "fim") {
        current_token->symbol = Symbols::SFIM;
    } else if (word == "escreva") {
        current_token->symbol = Symbols::SESCREVA;
    } else if (word == "leia") {
        current_token->symbol = Symbols::SLEIA;
    } else if (word == "var") {
        current_token->symbol = Symbols::SVAR;
    } else if (word == "inteiro") {
        current_token->symbol = Symbols::SINTEIRO;
    } else if (word == "booleano") {
        current_token->symbol = Symbols::SBOOLEANO;
    } else if (word == "verdadeiro") {
        current_token->symbol = Symbols::SVERDADEIRO;
    } else if (word == "falso") {
        current_token->symbol = Symbols::SFALSO;
    } else if (word == "procedimento") {
        current_token->symbol = Symbols::SPROCEDIMENTO;
    } else if (word == "funcao") {
        current_token->symbol = Symbols::SFUNCAO;
    } else if (word == "div") {
        current_token->symbol = Symbols::SDIV;
    } else if (word == "e") {
        current_token->symbol = Symbols::SE;
    } else if (word == "ou") {
        current_token->symbol = Symbols::SOU;
    } else if (word == "nao") {
        current_token->symbol = Symbols::SNAO;
    } else {
        current_token->symbol = Symbols::SIDENTIFICADOR;
    }
}

void Lexical::handle_digit() {
    std::string word;
    word = *c;
    get_character_from_file();
    while (isdigit(*c) && !file.eof()) {
        word += c;
        get_character_from_file();
    }

    current_token->symbol = Symbols::SNUMERO;
    current_token->lexem = word;

}

void Lexical::handle_aritmethic_operator() {
    std::string word;
    word = *c;
    get_character_from_file();

    current_token->lexem = word;

    if (word == "+") {
        current_token->symbol = Symbols::SMAIS;
    } else if (word == "-") {
        current_token->symbol = Symbols::SMENOS;
    } else if (word == "*") {
        current_token->symbol = Symbols::SMULT;
    }
}

void Lexical::handle_relational_operator() {
    std::string word;
    word = *c;
    current_token->lexem = word;
    get_character_from_file();

    if (word == ">") {
        if (*c == '=') {
            current_token->symbol = Symbols::SMAIORIG;
            word += c;
            current_token->lexem = word;
            get_character_from_file();
        } else
            current_token->symbol = Symbols::SMAIOR;
    } else if (word == "<") {
        if (*c == '=') {
            current_token->symbol = Symbols::SMENORIG;
            word += c;
            current_token->lexem = word;
            get_character_from_file();
        } else
            current_token->symbol = Symbols::SMENOR;
    } else if (word == "!") {
        if (*c == '=') {
            current_token->symbol = Symbols::SDIF;
            word += c;
            current_token->lexem = word;
            get_character_from_file();
        } else{
            current_token->symbol = Symbols::SERRO;
        }
    } else if (word == "=") {
        current_token->symbol = Symbols::SIG;
    }

}

void Lexical::handle_punctuation() {
    std::string word;
    word = *c;
    get_character_from_file();
    current_token->lexem = word;

    if (word == ";") {
        current_token->symbol = Symbols::SPONTO_VIRGULA;
    } else if (word == ",") {
        current_token->symbol = Symbols::SVIRGULA;
    } else if (word == "(") {
        current_token->symbol = Symbols::SABRE_PARENTESES;
    } else if (word == ")") {
        current_token->symbol = Symbols::SFECHA_PARENTESES;
    } else if (word == ".") {
        current_token->symbol = Symbols::SPONTO;
    }

}

void Lexical::handle_assignment() {
    std::string word;
    word = *c;
    get_character_from_file();
    if (*c == '=') { 
        word += *c;

        current_token->symbol = Symbols::SATRIBUICAO;
        current_token->lexem = word;

        get_character_from_file();
    } else {
        current_token->symbol = Symbols::SDOISPONTOS;
        current_token->lexem = word;
    }   
}
