#include <iostream>
#include <iomanip>

class FuncHandler {
private:
    double begin_value;
    double end_value;
    double step_value;
public:

    FuncHandler(double beginning, double end, double step = 1) {
        begin_value = beginning;
        end_value = end;
        step_value = step;           
    }

    ~FuncHandler() {
        std::cout << "\n" << "All tabulations are finished!";
    }

    void get_func_tabulation(bool include_endpoint = false) {
        std::cout << std::setw(3) << "x" << "      " << std::setw(3) << "y" << "\n";

        for (double i=begin_value; i<end_value; i+=step_value) {
            double y = sin(i) + cos(i);
            std::cout << std::setw(3) << i << "  " << std::setw(3) << y << "\n";
        }
        
        if (include_endpoint == true) {
            std::cout << std::setw(3) << end_value << "  " << std::setw(3) << sin(end_value)+cos(end_value) << "\n";
        }
    }
};


int main() {
    double b = 0;
    double e = 0;
    double s = 1;
    bool ip = false;
    std::cout << "Enter beggining of tabulation  ";
    std::cin >> b;
    std::cout << "\n" << "Enter end of tabulation  ";
    std::cin >> e;
    std::cout << "\n" << "Enter step of tabulation (default 1)  ";
    std::cin >> s;
    std::cout << "\n" << "Include edge points? (1/0)  ";
    std::cin >> ip;
    std::cout << "\n";

    FuncHandler tab_sin(b, e, s);
    tab_sin.get_func_tabulation(ip);

    return 0;
}