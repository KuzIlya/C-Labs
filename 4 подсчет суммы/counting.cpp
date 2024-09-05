#include <iostream>

int factorial(double num) {
    int result = 1;
    for (int i=1; i<=num; i++) {
        result *= i;
    }
    return result;
}

double pow(double n, int m) {
    if (m == 0 && n != 0) {
        return 1.0;
    } else if (m < 0) {
        return 1.0 / pow(n, -m);
    } else {
        double result = 1.0;
        for (int i = 0; i < m; i++) {
            result *= n;
        }
        return result;
    }
}

class Calc {
private:
    int end_value;
    double N_value;
    double i_value;
    double x_value;

public:
    Calc(int end_val, double N, double i, double x) {
        end_value = end_val;
        N_value = N;
        i_value = i;
        x_value = x;
    }

    double make_sum() {
        double result = 0;
        for (int i=1; i<=N_value; i++) {
            double current = (pow(-1, i_value) * factorial(2 * i_value - 1))\
            /(pow(x_value, i_value) * factorial(N_value-i_value));
            result += current;
        }
        return result;
    }
};

int main() {
    Calc sum(5,5,5,5);
    std::cout << sum.make_sum() << std::endl;
    return 0;
}