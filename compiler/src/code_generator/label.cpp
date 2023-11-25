#include "label.h"
#include <iostream>
#include <string>
#include <sstream>

int Label::label = 0;

std::string Label::getLabel() {
    return std::to_string(label);
}

void Label::setLabel(int value) {
    label = value;
}

int Label::incrementLabel(){
    Label::setLabel(std::stoi(Label::getLabel()) + 1);
    return label;
}