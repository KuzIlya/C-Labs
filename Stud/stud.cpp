#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Student {
public:
    char* name;
    int year;
    float mark;

    void print() {
        cout << name << " " << year << " " << mark << endl;
    }
};

int main() {
    Student* studentsArray[40];
    int numOfStudents = 0;
    char* studentName = new char[20];

    ifstream inputFile("student.txt");

    while (true) {
        inputFile >> studentName;
        if (inputFile.eof()) break;

        Student* student = new Student;
        student->name = new char[strlen(studentName) + 1];
        strcpy(student->name, studentName);
        inputFile >> student->year >> student->mark;
        studentsArray[numOfStudents++] = student;
    }

    for (int i = 0; i < numOfStudents; i++)
        studentsArray[i]->print();

    return 0;
}
