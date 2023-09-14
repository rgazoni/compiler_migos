#ifndef error_h
#define error_h

#include <iostream>

enum class Error
{
    ERROR1 = 62,
    ERROR2 = 126,
    COULD_NOT_OPEN_FILE = 1
    //...
};

void raiseError(Error error);

#endif
