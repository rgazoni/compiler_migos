#ifndef address_h
#define address_h

#include <iostream>
#include <string>

class Address {
public:
    static std::string getAddress();
    static void setAddress(int value);
    static int getVarCount();
    static void setVarCount(int value);
    static void incrementVarCount();


private:
    static int current_available_address;
    static int var_count;

};

#endif