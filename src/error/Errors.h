#ifndef error_h
#define error_h

#include <iostream>

enum class Error
{
    ERROR1 = 62,
    ERROR2 = 126,
    //...
};

void raiseError(Error error);

#endif
