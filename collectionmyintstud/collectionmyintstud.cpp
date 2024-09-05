#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class MyInt {
public:
    int data;

    void load(ifstream& file) {
        file >> data;
    }

    MyInt* insert(MyInt* item, MyInt** items, int count) {
        for (int i = 0; i < count; i++) {
            if (items[i]->data > item->data) {
                for (int j = count; j > i; j--) {
                    items[j] = items[j - 1];
                }
                items[i] = item;
                return items[0];
            }
        }
        items[count] = item;
        return items[0];
    }

    void print() {
        cout << data << " ";
    }
};

class Stud {
public:
    char* name;
    int year;
    float point;

    void load(ifstream& file) {
        char s[30];
        file >> s;
        if (!file.eof()) {
            name = new char[strlen(s) + 1];
            strcpy(name, s);
            file >> year >> point;
        }
    }

    Stud* insert(Stud* item, Stud** items, int count) {
        for (int i = 0; i < count; i++) {
            if (items[i]->point > item->point) {
                for (int j = count; j > i; j--) {
                    items[j] = items[j - 1];
                }
                items[i] = item;
                return items[0];
            }
        }
        items[count] = item;
        return items[0];
    }

    void print() {
        cout << name << " " << year << " " << point << " " << endl;
    }
};

template <typename T>
class Collection {
public:
    T** items;
    int limit;
    int delta;
    int count;

    Collection(int limit, int delta) {
        this->limit = limit;
        this->delta = delta;
        count = 0;
        items = new T * [limit];
    }

    void setLimit(int lim) {
        T** items2 = new T * [lim];
        for (int i = 0; i < count; i++) {
            items2[i] = items[i];
        }
        delete[] items;
        items = items2;
        limit = lim;
    }

    T* at(int index) {
        return items[index];
    }

    void load(ifstream& file) {
        while (true) {
            T* item = new T;
            item->load(file);
            insert(item);
            if (file.eof()) break;
        }
    }


    void print() {
        for (int i = 0; i < count; i++) {
            items[i]->print();
        }
        cout << endl;
    }

    void insert(T* item) {
        if (count == limit) setLimit(limit + delta);
        item->insert(item, items, count);
        count++;
    }

    ~Collection() {
        for (int i = 0; i < count; i++) {
            delete items[i];
        }
        delete[] items;
    }
};


int main() {
    ifstream file("MyInt.txt");

    Collection<MyInt> col(4, 2);
    col.load(file);
    col.print();

    file.close();

    ifstream file2("Stud.txt");

    Collection<Stud> col2(4, 2);
    col2.load(file2);
    col2.print();

    file2.close();
    return 0;
}
