#include "DVM.h"

int main(int argc, char *argv[]) {
    DVM dvm = DVM();

    dvm.executeFromFile("../objs/byte_code.obj");
    return 0;
}