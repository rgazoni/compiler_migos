#include "address.h"
#include <iostream>
#include <string>
#include <sstream>

int Address::current_available_address = 0;
int Address::var_count = 0;

std::string Address::getAddress() {
    return std::to_string(current_available_address);
}

int Address::getVarCount() {
    return var_count;
}

void Address::setAddress(int value) {
    current_available_address = value;
}

void Address::setVarCount(int value) {
    var_count = value;
}

void Address::incrementVarCount() {
    var_count = var_count + 1;
}