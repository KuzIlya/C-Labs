#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
    private:
        string surname;
        string birthday;
        double average_mark;
    
    public:
        Student(string second_name, string birth_date, double marks) {
            surname = second_name;
            birthday = birth_date;
            average_mark = marks;
        }
};

class TxtHandler {
    private:
        string text;
    
    public:
        TxtHandler() {
            ifstream textfile("stud.txt");
            getline(textfile, text, '\0');
            textfile.close();
        }

        string get_text() {
            return text;
        }


};

class PeopleArray {
    private:
        Student* data;

    public:
        PeopleArray(TxtHandler& file) {

        }

        void sort_by_surname() {

        }

        void sort_by_birthday() {

        }

        void sort_by_marks() {

        }
};

int main() { 
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); 
    TxtHandler file;
    cout << file.get_text();
}