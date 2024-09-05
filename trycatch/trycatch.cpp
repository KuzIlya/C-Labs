#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

class MyException : public std::exception {
private:
    std::string message;

public:
    MyException(const char* msg)
        : message(msg)
    {
    }

    const char* what() const throw()
    {
        return message.c_str();
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string filename;
    while (1) {
        std::cout << "Введите имя файла: ";
        std::cin >> filename;
        try {
            std::ifstream file(filename);

            if (!file.is_open()) {
                throw MyException("Файл не найден или не удалось открыть");
            }

            std::cout << "Содержимое файла " << filename << ":\n";
            std::string line;
            while (std::getline(file, line)) {
                std::cout << line << std::endl;
            }

            file.close();
        }
        catch (const std::exception& e) {
            std::cerr << "Ошибка: " << e.what() << std::endl;
        }
    }
    return 0;
}