#include "address.h"
#include <iostream>
#include <string>
#include <sstream>

int Address::current_available_address = 0;

std::string Address::getAddress() {
    return std::to_string(current_available_address);
}

void Address::setAddress(int value) {
    current_available_address = value;
}

int Address::incrementAddress(){
    Address::setAddress(std::stoi(Address::getAddress()) + 1);
    return current_available_address;
}