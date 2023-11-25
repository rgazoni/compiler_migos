#include "DVM.h"

int main(int argc, char *argv[]) {
    DVM dvm = DVM();

    dvm.executeFromFile("byte_code.obj");
    return 0;
}