#include <iostream>
#include <string>
#include "Table.h"
using namespace std;

template<typename Key_Type, typename Info_Type>
Node<Key_Type, Info_Type>::Node(Key_Type ident, const Info_Type& inform) : id(ident), info(inform), next(nullptr) {}

template<typename Key_Type, typename Info_Type>
ostream& operator<<(ostream& os, Node<Key_Type, Info_Type>& a) {
    os << a.info;
    return os;
}

template<typename Key_Type, typename Info_Type>
AbstractTable<Key_Type, Info_Type>::~AbstractTable() {
    while (head != nullptr) {
        Node<Key_Type, Info_Type>* cur = head;
        head = head->next;
        delete cur;
    }
}

template<typename Key_Type, typename Info_Type>
void Table<Key_Type, Info_Type>::insert(const Key_Type& key, const Info_Type& value) {
    Node<Key_Type, Info_Type>* newNode = new Node<Key_Type, Info_Type>(key, value);
    newNode->next = Table<Key_Type, Info_Type>::head;
    //Table<Key_Type, Info_Type>::
        head = newNode;
}

template<typename Key_Type, typename Info_Type>
Node<Key_Type, Info_Type>* Table<Key_Type, Info_Type>::find(const Key_Type& key) {
    Node<Key_Type, Info_Type>* current = Table<Key_Type, Info_Type>::head;
    while (current && current->id != key) {
        current = current->next;
    }
    if (current->id != key) {
        return nullptr;
    }
    return current;
}

template<typename Key_Type, typename Info_Type>
void SortedTable<Key_Type, Info_Type>::insert(const Key_Type& key, const Info_Type& value) {
    Node<Key_Type, Info_Type>* newNode = new Node<Key_Type, Info_Type>(key, value);
    if (!SortedTable<Key_Type, Info_Type>::head || SortedTable<Key_Type, Info_Type>::head->id >= key) {
        newNode->next = SortedTable<Key_Type, Info_Type>::head;
        SortedTable<Key_Type, Info_Type>::head = newNode;
    }
    else {
        Node<Key_Type, Info_Type>* current = SortedTable<Key_Type, Info_Type>::head;
        while (current->next && current->next->id < key) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

template<typename Key_Type, typename Info_Type>
Node<Key_Type, Info_Type>* SortedByFreequencyTable<Key_Type, Info_Type>::find(const Key_Type& key) {
    Node<Key_Type, Info_Type>* current = SortedByFreequencyTable<Key_Type, Info_Type>::head;
    Node<Key_Type, Info_Type>* prev = nullptr;
    while (current && current->id != key) {
        prev = current;
        current = current->next;
    }
    if (current && prev) {
        prev->next = current->next;
        current->next = SortedByFreequencyTable<Key_Type, Info_Type>::head;
        SortedByFreequencyTable<Key_Type, Info_Type>::head = current;
    }
    return current;
}

template<typename Key_Type, typename Info_Type>
bool AbstractTable<Key_Type, Info_Type>::is_empty() {
    return head == nullptr;
}

template<typename Key_Type, typename Info_Type>
void AbstractTable<Key_Type, Info_Type>::display() {
    if (is_empty() == 0) {
        Node<Key_Type, Info_Type>* current = head;
        while (current != nullptr) {
            cout << "Ключ: " << current->id << "\tСодержимое: " << current->info << endl;
            current = current->next;
        }
    }
    else {
        cout << "Table is empty" << endl;
    }
}

template<typename Key_Type, typename Info_Type>
void AbstractTable<Key_Type, Info_Type>::del(const Key_Type& key) {
    if (head == nullptr) return;

    Node<Key_Type, Info_Type>* current = head;
    Node<Key_Type, Info_Type>* prev = nullptr;
    while (current && current->id != key) {
        prev = current;
        current = current->next;
    }
    if (current == nullptr) return;

    if (prev == nullptr) {
        head = head->next;
    }
    else {
        prev->next = current->next;
    }
    delete current;
}


int main() {
    setlocale(LC_ALL, "Russian");
    //Table<int, const char*> *a[3];
    //a[0] = new Table<int, const char*>;
    //a[1] = new SortedTable<int, const char*>;
    //a[2] = new SortedByFreequencyTable<int, const char*>;

    //for (int i = 0; i < 3; i++) {
    //    a[i]->insert(3, "1");
    //    a[i]->insert(1, "2");
    //    a[i]->insert(4, "3");
    //    a[i]->insert(2, "4");
    //    a[i]->find(3);
    //    a[i]->display();

    //    cout << endl;
    //}
    Table<int, const char*> a;
    a.insert(2, "2");
    a.insert(1, "1");
    a.insert(3, "3");
    std::cout << a.find(4)->info << std::endl;
    a.display();
    return 0;
}