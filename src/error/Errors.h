#ifndef error_h
#define error_h

#include <iostream>

enum class Error
{
    TOKEN_NOT_VALID,
    ERROR2 = 126,
    COULD_NOT_OPEN_FILE = 1
    //...
};

void raiseError(Error error);

#endif
