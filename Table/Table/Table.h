#include <iostream>
#include <string>
using namespace std;

template<typename Key_Type, typename Info_Type>
class Node {
public:
    Key_Type id;
    Info_Type info;
    Node<Key_Type, Info_Type>* next;

    Node(Key_Type ident, const Info_Type& inform);
};

template<typename Key_Type, typename Info_Type>
ostream& operator<<(ostream& os, Node<Key_Type, Info_Type>& a);

template<typename Key_Type, typename Info_Type>
class AbstractTable {
public:
    Node<Key_Type, Info_Type>* head;

    AbstractTable() : head(nullptr) {}
    virtual ~AbstractTable();

    virtual void insert(const Key_Type& key, const Info_Type& value) = 0;
    virtual Node<Key_Type, Info_Type>* find(const Key_Type& key) = 0;
    void del(const Key_Type& key);
    bool is_empty();
    void display();
};

template<typename Key_Type, typename Info_Type>
class Table: public AbstractTable<Key_Type, Info_Type> {
public:
    void insert(const Key_Type& key, const Info_Type& value) override;
    Node<Key_Type, Info_Type>* find(const Key_Type& key) override;
};

template<typename Key_Type, typename Info_Type>
class SortedTable: public Table<Key_Type, Info_Type> {
public:
    void insert(const Key_Type& key, const Info_Type& value) override;
};

template<typename Key_Type, typename Info_Type>
class SortedByFreequencyTable: public Table<Key_Type, Info_Type> {
public:
    Node<Key_Type, Info_Type>* find(const Key_Type& key) override;
};
