#include <iostream>
#include <iomanip>

class NumHandler {
private:
    int number;
public:
    NumHandler(int num) {
        number = num;
    }

    bool DivisibleByAllDigits(int num) {
        int originalNum = num;
        while (num > 0) {
            int digit = num % 10;
            if (digit == 0 || originalNum % digit != 0) {
                return false;
            }
            num /= 10;
        }
        return true;
    }

    void NumCheck() {
        std::cout << "Numbers divisible by all their digits from 1 to " << number << " are:" << std::endl;
        int count = 0; 
        for (int i = 1; i <= number; ++i) {
            if (DivisibleByAllDigits(i)) {
                std::cout << std::setw(4) << i << " "; 
                count++;
                if (count == 8) { 
                    std::cout << std::endl; 
                    count = 0;
                }
            }
        }
        std::cout << std::endl;
    } 
};

int main() {
    int num;
    std::cout << "Enter number (int)  ";
    std::cin >> num;

    NumHandler n(num);
    n.NumCheck();
}