#ifndef address_h
#define address_h

#include <iostream>
#include <string>

class Address {
public:
    static std::string getAddress();
    static void setAddress(int value);
    static std::string getVarCount();
    static void setVarCount(int value);


private:
    static int current_available_address;
    static int var_count;

};

#endif