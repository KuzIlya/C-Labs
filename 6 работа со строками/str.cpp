#include <iostream>
#include <cstring>
#include <cstdlib>

int main() {
    const char* inputString = "aaa bcd aa t";

    int count[256] = {0}; 

    for (int i = 0; i < strlen(inputString); i++) {
        count[ static_cast<int>(inputString[i]) ]++;
    }

    std::cout << "Count of every char:" << std::endl;
    for (int i = 0; i < 256; i++) {
        if (count[i] > 0) {
            std::cout << static_cast<char>(i) << ": " << count[i] << std::endl;
        }
    }

    return 0;
}
