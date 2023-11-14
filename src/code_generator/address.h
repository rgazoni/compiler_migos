#ifndef address_h
#define address_h

#include <iostream>
#include <string>

class Address {
public:
    static std::string getAddress();
    static void setAddress(int value);
    static int incrementAddress();

private:
    static int address;
};

#endif