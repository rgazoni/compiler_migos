#include "Errors.h"
#include <iostream>

void raiseError(Error error)
{
    switch(error)
    {
        case Error::TOKEN_NOT_VALID:
            std::cout << "ERROR CODE: " << (int) Error::TOKEN_NOT_VALID << std::endl;
            std::cout << "MESSAGE: Symbol received not valid" << std::endl;
            break;
        case Error::ERROR2:
            std::cout << "Error 2" << std::endl;
            break;
        case Error::COULD_NOT_OPEN_FILE:
            std::cout << "ERROR CODE: " << (int) Error::COULD_NOT_OPEN_FILE << std::endl;
            std::cout << "MESSAGE: Could not open file" << std::endl;
            break;
        default:
            std::cout << "Unknown error" << std::endl;
            break;
    }
    exit(1);
}
