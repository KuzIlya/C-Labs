#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Student {
public:
    char* name;
    int year;
    float mark;

    Student(const char* studentName, int studentYear, float studentMark) : year(studentYear), mark(studentMark) {
        name = new char[strlen(studentName) + 1];
        strcpy(name, studentName);
    }

    void print() {
        cout << name << " " << year << " " << mark << endl;
    }
};

class ListNode {
public:
    Student* data;
    ListNode* next;

    ListNode(Student* student) : data(student), next(nullptr) {}

    void print() {
        data->print();
    }
};

class LinkedList {
public:
    ListNode* head;

    LinkedList() : head(nullptr) {}

    void push(ListNode* node) {
        if (!head || strcmp(node->data->name, head->data->name) < 0) {
            node->next = head;
            head = node;
        } 
        else {
            ListNode* current = head;
            while (current->next && strcmp(node->data->name, current->next->data->name) >= 0) {
                current = current->next;
            }
            node->next = current->next;
            current->next = node;
        }
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
        char studentName[20];
        inputFile >> studentName;
        if (inputFile.eof()) break;

        int studentYear;
        float studentMark;
        inputFile >> studentYear >> studentMark;

        studentsArray[numOfStudents++] = new Student(studentName, studentYear, studentMark);
    }

    LinkedList studentList;
    for (int i = 0; i < numOfStudents; i++)
        studentList.push(new ListNode(studentsArray[i]));

    studentList.print();

    return 0;
}
