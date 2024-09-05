#include <iostream>

extern "C" const char* mystrstr(const char* string, const char* substring);


int main() {
    const char* string{ "Lorem ipsum dolor sit amet, consectetur adipiscing elit." };
    const char* substring{ "consectetur" };
    const char* mas[2];
    mas[0] = mystrstr(string, substring);
    mas[1] = strstr(string, substring);
    for (int i = 0; i < 2; i++) {
        if (mas[i]) {
            std::cout << mas[i] << std::endl;
        }
        else {
            std::cout << "nullptr" << std::endl;
        }
    }
    return 0;
}