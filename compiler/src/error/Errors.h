#ifndef error_h
#define error_h

#include <iostream>

enum class Error : u_int8_t
{
    //Lexical errors
    TOKEN_NOT_VALID,
    COULD_NOT_OPEN_FILE,

    //Syntax errors
    EXPECTED_EOF,
    EXPECTED_DOT,
    EXPECTED_COMMA,
    EXPECTED_SEMICOLON,
    EXPECTED_IDENTIFIER,
    EXPECTED_RESERVED_WORD_PROGRAMA,

    // SYMBOL_EQUALS_COLON,
    EXPECTED_COMMA_OR_COLON,
    NOT_EXPECTED_COLON,
    NOT_IDENTIFIER,
    EXPECTED_CLOSE_PARENTHESIS,
    EXPECTED_ELEMENT,
    EXPECTED_BOOLEAN_OR_INT,
    // IS_NOT_BOOLEAN_OR_INT,
    IS_NOT_SEMICOLON,
    EXPECTED_COLON,
    EXPECTED_OPEN_PARENTHESIS,
    EXPECTED_SENTAO,
    // PARENTHESIS_DOES_NOT_CLOSE,
    // INCORRECT_LEXEM

    //SYMBOL_TABLE_ERROS
    EXPECTED_ANOTHER_VARIABLE_NAME,
    EXPECTED_ANOTHER_PROCEDURE_NAME,
    EXPECTED_ANOTHER_FUNCTION_NAME,
    EXPECTED_VARIABLE_DECLARATION

    //Semantic errors
    
};

void raiseError(Error error);

#endif
