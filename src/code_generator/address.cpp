#include "address.h"
#include <iostream>
#include <string>
#include <sstream>

int Address::address = 0;

std::string Address::getAddress() {
    return std::to_string(address);
}

void Address::setAddress(int value) {
    address = value;
}

int Address::incrementAddress(){
    Address::setAddress(std::stoi(Address::getAddress()) + 1);
    return address;
}