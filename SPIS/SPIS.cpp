#include <iostream>
#include <string> 
#include <vector>

namespace myclass {

    template<typename Type>
    struct Node 
    {
        Type info;
        Node(const Type info) : info(info) {}
    };

    template<typename Type>
    struct Elem 
    {
        Node<Type> info;
        Elem<Type>* next;

        Elem(const Node<Type>& info) : info(info), next(nullptr) {}
        Elem(const Node<Type>& info, Elem<Type>* next) : info(info), next(next) {}
        ~Elem() 
        {
        }
    };

    template<typename Type>
    class Spis {
    protected:
        Elem<Type>* head;
    public:
        Spis() : head(nullptr) {}
        Spis(Elem<Type>* info) : head(info) {}
        virtual ~Spis() 
        { 
            if (head != nullptr) delete head; 
        }

        virtual void push(Type value) = 0;
        virtual Type pop() = 0;

        virtual void QueuePush(Type value) {};
        virtual Type QueuePop() { return NULL; };

        virtual void init(Type* values)
        {
            std::cout << std::endl << "--------------------------------------------------------------" << std::endl << std::endl;

            for (int i = 0; i < 4; i++)
            {
                push(values[i]);
            }
            print();
            std::cout << "Popped Value : " << pop() << std::endl;
            print();
        }

        bool isEmpty() const 
        {
            return this->head == nullptr;
        }

        void print()
        {
            Elem<Type>* current = head;
            while (current != nullptr) 
            {
                std::cout << current->info.info << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }
    };

    template<typename Type>
    class Stack : virtual public Spis<Type> 
    {
    public:
        Stack() : Spis<Type>(nullptr) {}
        virtual ~Stack() {}

        void push(Type value) override 
        {
            Elem<Type>* newNode = new Elem<Type>(Node<Type>(value), this->head);
            this->head = newNode;
        }

        Type pop() override 
        {
            if (this->head == nullptr) 
            {
                throw std::out_of_range("Stack is empty");
            }
            Type value = this->head->info.info;
            Elem<Type>* temp = this->head;
            this->head = this->head->next;
            delete temp;
            return value;
        }

    };

    template<typename Type>
    class Queue : virtual public Spis<Type> {
    public:
        Queue() : Spis<Type>(nullptr) {}
        virtual ~Queue() {}

        void push(Type value) override {
            if (this->head == nullptr) {
                this->head = new Elem<Type>(Node<Type>(value));
            }
            else {
                Elem<Type>* current = this->head;
                while (current->next != nullptr) {
                    current = current->next;
                }
                current->next = new Elem<Type>(Node<Type>(value));
            }
        };

        Type pop() override {
            if (this->head == nullptr) {
                throw std::out_of_range("Queue is empty");
            }
            Type value = this->head->info.info;
            Elem<Type>* temp = this->head;
            this->head = this->head->next;
            delete temp;
            return value;
        }

    };

    template<typename Type>
    class Deque : public Stack<Type>, public Queue<Type> {
    public:
        Deque() {}
        virtual ~Deque() {}

        void push(Type value) override {
            Stack<Type>::push(value);
        };

        Type pop() override {
            return Stack<Type>::pop();
        };

        void QueuePush(Type value) {
            Queue<Type>::push(value);
        }

        Type QueuePop() {
            return Queue<Type>::pop();
        };

        void init(Type* values) override
        {
            Spis<Type>::init(values);

            std::cout << std::endl;
            QueuePush(values[4]);
            Deque<Type>::print();
            std::cout << "Popped Value : " << QueuePop() << std::endl;
            Deque<Type>::print();
        }

    };
}

int main() {
    
    #define Type std::string

    int* values_1 = new int[5]{1, 2, 3, 4, 5};
    std::string* values_2 = new std::string[5]{ "aaa", "bbb", "ccc", "ddd", "eee" };

    myclass::Spis<Type>* a[3];
    a[0] = new myclass::Stack<Type>();
    a[1] = new myclass::Queue<Type>();
    a[2] = new myclass::Deque<Type>();

    for (int i = 0; i < 3; i++)
    {
        a[i]->init(values_2);
    }

    myclass::Spis<int>* b[3];
    b[0] = new myclass::Stack<int>();
    b[1] = new myclass::Queue<int>();
    b[2] = new myclass::Deque<int>();

    for (int i = 0; i < 3; i++)
    {
        b[i]->init(values_1);
    }

    return 0;
}