#ifndef label_h
#define label_h

#include <iostream>
#include <string>

class Label {
public:
    static std::string getLabel();
    static void setLabel(int value);
    static int incrementLabel();

private:
    static int label;
};

#endif