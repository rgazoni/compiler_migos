#ifndef error_h
#define error_h

#include <iostream>

enum class Error
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



    //Semantic errors


};

void raiseError(Error error);

#endif
