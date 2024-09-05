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
        cout << name << " " << year << " " << mark << " " << endl;
    };
};

class ListNode {
public:
    Student* data; 
    ListNode* next; 

    ListNode(Student* student) {
        data = student;
    }

    void print() {
        data->print();
    }
};

class LinkedList {
public:
    ListNode* head; 

    LinkedList() {
        head = nullptr;
    }

    void push(ListNode* node) {
        node->next = head;
        head = node;
    }

    void print() {
        ListNode* current = head;
        while (current != nullptr) {
            current->print();
            current = current->next;
        }
    }
};

int main() {
    Student* studentsArray[250];
    int numOfStudents = 0; 

    ifstream inputFile("student.txt");

    while (true) {
        char* studentName = new char[20];
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
    cout << endl;

    LinkedList studentList;
    for (int i = 0; i < numOfStudents; i++)
        studentList.push(new ListNode(studentsArray[i]));

    studentList.print();

    return 0;
}