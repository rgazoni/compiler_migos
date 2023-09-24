#include "Errors.h"
#include "../lexical_analyser.h"
#include <iostream>

void raiseError(Error error)
{
    std::cout << "ERROR LINE: " << Lexical::get_execution_line() << std::endl;
    std::cout << "ERROR COLUMN: " << Lexical::get_execution_column() << std::endl;
    switch(error)
    {
        case Error::TOKEN_NOT_VALID:
            std::cout << "ERROR CODE: " << (int) Error::TOKEN_NOT_VALID << std::endl;
            std::cout << "MESSAGE: Symbol received not valid" << std::endl;
            break;
        case Error::COULD_NOT_OPEN_FILE:
            std::cout << "ERROR CODE: " << (int) Error::COULD_NOT_OPEN_FILE << std::endl;
            std::cout << "MESSAGE: Could not open file" << std::endl;
            break;
        case Error::EXPECTED_EOF:
            std::cout << "ERROR CODE: " << (int) Error::EXPECTED_EOF << std::endl;
            std::cout << "MESSAGE: Expected end of file" << std::endl;
            break;
        case Error::EXPECTED_DOT:
            std::cout << "ERROR CODE: " << (int) Error::EXPECTED_DOT << std::endl;
            std::cout << "MESSAGE: Expected dot" << std::endl;
            break;
        case Error::EXPECTED_COMMA:
            std::cout << "ERROR CODE: " << (int) Error::EXPECTED_COMMA << std::endl;
            std::cout << "MESSAGE: Expected comma" << std::endl;
            break;
        case Error::EXPECTED_SEMICOLON:
            std::cout << "ERROR CODE: " << (int) Error::EXPECTED_SEMICOLON << std::endl;
            std::cout << "MESSAGE: Expected semicolon" << std::endl;
            break;
        case Error::EXPECTED_IDENTIFIER:
            std::cout << "ERROR CODE: " << (int) Error::EXPECTED_IDENTIFIER << std::endl;
            std::cout << "MESSAGE: Expected identifier" << std::endl;
            break;
        case Error::EXPECTED_RESERVED_WORD_PROGRAMA:
            std::cout << "ERROR CODE: " << (int) Error::EXPECTED_RESERVED_WORD_PROGRAMA << std::endl;
            std::cout << "MESSAGE: Expected reserved word 'programa'" << std::endl;
            break;
        default:
            std::cout << "Unknown error" << std::endl;
            break;
    }
    exit(1);
}
