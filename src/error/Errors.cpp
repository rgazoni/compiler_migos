#include "Errors.h"
#include "../lexical_analyser.h"
#include <iostream>

void raiseError(Error error) {
    Lexical lexical;

    std::cout << "ERROR LINE: " << lexical.get_execution_line() << std::endl;
    std::cout << "ERROR COLUMN: " << lexical.get_execution_column() << std::endl;
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
        case Error::NOT_EXPECTED_COLON:
            std::cout << "ERROR CODE: " << (int) Error::NOT_EXPECTED_COLON << std::endl;
            std::cout << "MESSAGE: Colon not expected" << std::endl;
            break;
        case Error::EXPECTED_COMMA_OR_COLON:
            std::cout << "ERROR CODE: " << (int) Error::EXPECTED_COMMA_OR_COLON << std::endl;
            std::cout << "MESSAGE: Is not comma or colon" << std::endl;
            break;
        case Error::EXPECTED_BOOLEAN_OR_INT:
            std::cout << "ERROR CODE: " << (int) Error::EXPECTED_BOOLEAN_OR_INT << std::endl;
            std::cout << "MESSAGE: Expected boolean or int type" << std::endl;
            break;
        case Error::EXPECTED_CLOSE_PARENTHESIS:
            std::cout << "ERROR CODE: " << (int) Error::EXPECTED_CLOSE_PARENTHESIS << std::endl;
            std::cout << "MESSAGE: Expected close parenthesis" << std::endl;
            break;
        case Error::EXPECTED_ELEMENT:
            std::cout << "ERROR CODE: " << (int) Error::EXPECTED_ELEMENT << std::endl;
            std::cout << "MESSAGE: Expected element" << std::endl;
            break;
        case Error::EXPECTED_COLON:
            std::cout << "ERROR CODE: " << (int) Error::EXPECTED_COLON << std::endl;
            std::cout << "MESSAGE: Expected colon" << std::endl;
            break;
        case Error::EXPECTED_OPEN_PARENTHESIS:
            std::cout << "ERROR CODE: " << (int) Error::EXPECTED_OPEN_PARENTHESIS << std::endl;
            std::cout << "MESSAGE: Expected open parenthesis" << std::endl;
            break;
        // case Error::INCORRECT_LEXEM:
        //     std::cout << "ERROR CODE: " << (int) Error::INCORRECT_LEXEM << std::endl;
        //     std::cout << "MESSAGE: Lexem is incorrect" << std::endl;
        //     break;
        case Error::EXPECTED_SENTAO:
            std::cout << "ERROR CODE: " << (int) Error::EXPECTED_SENTAO << std::endl;
            std::cout << "MESSAGE: Expected entao" << std::endl;
            break;
        default:
            std::cout << "Unknown error" << std::endl;
            break;
    }
    exit(1);
}
