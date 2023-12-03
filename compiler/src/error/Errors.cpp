#include "Errors.h"
#include "../ui/application.h"
#include "../lexical/lexical_analyzer.h"
#include <iostream>

void raiseError(Error error) {
    Lexical lexical;
    std::string message;

    message = std::string("ERROR LINE: ") + std::to_string(lexical.get_execution_line()) + "\n";
    message += std::string("ERROR COLUMN: ") + std::to_string(lexical.get_execution_column()) + "\n";
    switch(error)
    {
        case Error::TOKEN_NOT_VALID:
            std::cout << "ERROR CODE: " << (int) Error::TOKEN_NOT_VALID << std::endl;
            std::cout << "MESSAGE: Symbol received not valid" << std::endl;
            message += std::string("ERROR CODE: ") + std::to_string((int) Error::TOKEN_NOT_VALID) + "\n";
            message += std::string("MESSAGE: Symbol received not valid") + "\n";
            break;
        case Error::COULD_NOT_OPEN_FILE:
            std::cout << "ERROR CODE: " << (int) Error::COULD_NOT_OPEN_FILE << std::endl;
            std::cout << "MESSAGE: Could not open file" << std::endl;
            message += std::string("ERROR CODE: ") + std::to_string((int) Error::COULD_NOT_OPEN_FILE) + "\n";
            message += std::string("MESSAGE: Could not open file") + "\n";
            break;
        case Error::EXPECTED_EOF:
            std::cout << "ERROR CODE: " << (int) Error::EXPECTED_EOF << std::endl;
            std::cout << "MESSAGE: Expected end of file" << std::endl;
            message += std::string("ERROR CODE: ") + std::to_string((int) Error::EXPECTED_EOF) + "\n";
            message += std::string("MESSAGE: Expected end of file") + "\n";
            break;
        case Error::EXPECTED_DOT:
            std::cout << "ERROR CODE: " << (int) Error::EXPECTED_DOT << std::endl;
            std::cout << "MESSAGE: Expected dot" << std::endl;
            message += std::string("ERROR CODE: ") + std::to_string((int) Error::EXPECTED_DOT) + "\n";
            message += std::string("MESSAGE: Expected dot") + "\n";
            break;
        case Error::EXPECTED_COMMA:
            std::cout << "ERROR CODE: " << (int) Error::EXPECTED_COMMA << std::endl;
            std::cout << "MESSAGE: Expected comma" << std::endl;
            message += std::string("ERROR CODE: ") + std::to_string((int) Error::EXPECTED_COMMA) + "\n";
            message += std::string("MESSAGE: Expected comma") + "\n";
            break;
        case Error::EXPECTED_SEMICOLON:
            std::cout << "ERROR CODE: " << (int) Error::EXPECTED_SEMICOLON << std::endl;
            std::cout << "MESSAGE: Expected semicolon" << std::endl;
            message += std::string("ERROR CODE: ") + std::to_string((int) Error::EXPECTED_SEMICOLON) + "\n";
            message += std::string("MESSAGE: Expected semicolon") + "\n";
            break;
        case Error::EXPECTED_IDENTIFIER:
            std::cout << "ERROR CODE: " << (int) Error::EXPECTED_IDENTIFIER << std::endl;
            std::cout << "MESSAGE: Expected identifier" << std::endl;
            message += std::string("ERROR CODE: ") + std::to_string((int) Error::EXPECTED_IDENTIFIER) + "\n";
            message += std::string("MESSAGE: Expected identifier") + "\n";
            break;
        case Error::EXPECTED_RESERVED_WORD_PROGRAMA:
            std::cout << "ERROR CODE: " << (int) Error::EXPECTED_RESERVED_WORD_PROGRAMA << std::endl;
            std::cout << "MESSAGE: Expected reserved word 'programa'" << std::endl;
            message += std::string("ERROR CODE: ") + std::to_string((int) Error::EXPECTED_RESERVED_WORD_PROGRAMA) + "\n";
            message += std::string("MESSAGE: Expected reserved word 'programa'") + "\n";
            break;
        case Error::NOT_EXPECTED_COLON:
            std::cout << "ERROR CODE: " << (int) Error::NOT_EXPECTED_COLON << std::endl;
            std::cout << "MESSAGE: Colon not expected" << std::endl;
            message += std::string("ERROR CODE: ") + std::to_string((int) Error::NOT_EXPECTED_COLON) + "\n";
            message += std::string("MESSAGE: Colon not expected") + "\n";
            break;
        case Error::EXPECTED_COMMA_OR_COLON:
            std::cout << "ERROR CODE: " << (int) Error::EXPECTED_COMMA_OR_COLON << std::endl;
            std::cout << "MESSAGE: Is not comma or colon" << std::endl;
            message += std::string("ERROR CODE: ") + std::to_string((int) Error::EXPECTED_COMMA_OR_COLON) + "\n";
            message += std::string("MESSAGE: Is not comma or colon") + "\n";
            break;
        case Error::EXPECTED_BOOLEAN_OR_INT:
            std::cout << "ERROR CODE: " << (int) Error::EXPECTED_BOOLEAN_OR_INT << std::endl;
            std::cout << "MESSAGE: Expected boolean or int type" << std::endl;
            message += std::string("ERROR CODE: ") + std::to_string((int) Error::EXPECTED_BOOLEAN_OR_INT) + "\n";
            message += std::string("MESSAGE: Expected boolean or int type") + "\n";
            break;
        case Error::EXPECTED_CLOSE_PARENTHESIS:
            std::cout << "ERROR CODE: " << (int) Error::EXPECTED_CLOSE_PARENTHESIS << std::endl;
            std::cout << "MESSAGE: Expected close parenthesis" << std::endl;
            message += std::string("ERROR CODE: ") + std::to_string((int) Error::EXPECTED_CLOSE_PARENTHESIS) + "\n";
            message += std::string("MESSAGE: Expected close parenthesis") + "\n";
            break;
        case Error::EXPECTED_ELEMENT:
            std::cout << "ERROR CODE: " << (int) Error::EXPECTED_ELEMENT << std::endl;
            std::cout << "MESSAGE: Expected element" << std::endl;
            message += std::string("ERROR CODE: ") + std::to_string((int) Error::EXPECTED_ELEMENT) + "\n";
            message += std::string("MESSAGE: Expected element") + "\n";
            break;
        case Error::EXPECTED_COLON:
            std::cout << "ERROR CODE: " << (int) Error::EXPECTED_COLON << std::endl;
            std::cout << "MESSAGE: Expected colon" << std::endl;
            message += std::string("ERROR CODE: ") + std::to_string((int) Error::EXPECTED_COLON) + "\n";
            message += std::string("MESSAGE: Expected colon") + "\n";
            break;
        case Error::EXPECTED_OPEN_PARENTHESIS:
            std::cout << "ERROR CODE: " << (int) Error::EXPECTED_OPEN_PARENTHESIS << std::endl;
            std::cout << "MESSAGE: Expected open parenthesis" << std::endl;
            message += std::string("ERROR CODE: ") + std::to_string((int) Error::EXPECTED_OPEN_PARENTHESIS) + "\n";
            message += std::string("MESSAGE: Expected open parenthesis") + "\n";
            break;
        // case Error::INCORRECT_LEXEM:
        //     std::cout << "ERROR CODE: " << (int) Error::INCORRECT_LEXEM << std::endl;
        //     std::cout << "MESSAGE: Lexem is incorrect" << std::endl;
        //     break;
        case Error::EXPECTED_SENTAO:
            std::cout << "ERROR CODE: " << (int) Error::EXPECTED_SENTAO << std::endl;
            std::cout << "MESSAGE: Expected entao" << std::endl;
            message += std::string("ERROR CODE: ") + std::to_string((int) Error::EXPECTED_SENTAO) + "\n";
            message += std::string("MESSAGE: Expected entao") + "\n";
            break;
        case Error::EXPECTED_ANOTHER_VARIABLE_NAME:
            std::cout << "ERROR CODE: " << (int) Error::EXPECTED_ANOTHER_VARIABLE_NAME << std::endl;
            std::cout << "MESSAGE: Variable already declared" << std::endl;
            message += std::string("ERROR CODE: ") + std::to_string((int) Error::EXPECTED_ANOTHER_VARIABLE_NAME) + "\n";
            message += std::string("MESSAGE: Variable already declared") + "\n";
            break;
        case Error::EXPECTED_ANOTHER_PROCEDURE_NAME:
            std::cout << "ERROR CODE: " << (int) Error::EXPECTED_ANOTHER_PROCEDURE_NAME << std::endl;
            std::cout << "MESSAGE: Name already used" << std::endl;
            message += std::string("ERROR CODE: ") + std::to_string((int) Error::EXPECTED_ANOTHER_PROCEDURE_NAME) + "\n";
            message += std::string("MESSAGE: Name already used") + "\n";
            break;
        case Error::EXPECTED_ANOTHER_FUNCTION_NAME:
            std::cout << "ERROR CODE: " << (int) Error::EXPECTED_ANOTHER_FUNCTION_NAME << std::endl;
            std::cout << "MESSAGE: Name already used" << std::endl;
            message += std::string("ERROR CODE: ") + std::to_string((int) Error::EXPECTED_ANOTHER_FUNCTION_NAME) + "\n";
            message += std::string("MESSAGE: Name already used") + "\n";
            break;
        case Error::EXPECTED_VARIABLE_DECLARATION:
            std::cout << "ERROR CODE: " << (int) Error::EXPECTED_VARIABLE_DECLARATION << std::endl;
            std::cout << "MESSAGE: Variable is undefined" << std::endl;
            message += std::string("ERROR CODE: ") + std::to_string((int) Error::EXPECTED_VARIABLE_DECLARATION) + "\n";
            message += std::string("MESSAGE: Variable is undefined") + "\n";
            break;
        default:
            std::cout << "Unknown error" << std::endl;
            message += std::string("MESSAGE: Unknown error") + "\n";
            break;
    }
    Application::win->m_refErrorsBuffer->set_text(message);
}
