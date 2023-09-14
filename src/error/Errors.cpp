#include "Errors.h"
#include <iostream>

void raiseError(Error error)
{
    switch(error)
    {
        case Error::ERROR1:
            std::cout << "Error 1" << std::endl;
            break;
        case Error::ERROR2:
            std::cout << "Error 2" << std::endl;
            break;
        default:
            std::cout << "Unknown error" << std::endl;
            break;
        exit(1);
    }
}
