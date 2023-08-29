#include <iostream>
#include <fstream>

void unnecessary_characters_dump (char c, std::ifstream &file);

int main (int argc, char *argv[]) {
    std::ifstream file;
    file.open(argv[1]);
    if (!file.is_open()) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }
    char c;
    while (file.get(c)) {
        unnecessary_characters_dump(c, file);
    }
    file.close();
    return 0;
}

void unnecessary_characters_dump (char c, std::ifstream &file) {
    while ((c == '{' || c == ' ') && !file.eof() ) {
        if (c == '{') {
            while (c != '}' && !file.eof()) {
                file.get(c);
            }
            file.get(c);
            while(c == ' ' && !file.eof()) {
                file.get(c);
            }
        }
    }
    if ( !file.eof() ) {
        std::cout << c;
    }
}

