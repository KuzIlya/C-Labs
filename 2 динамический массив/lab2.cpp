#include <iostream>

class DynamicArray {
private:
    int* data;
    int length;
    
public:
    DynamicArray(int size = 0) {
        length = size;
        data = new int[size];
    }

    ~DynamicArray() {
        delete[] data;
    }

    void Resize(int newLength) {
        int* newData = new int[newLength];
        for (int i = 0; i < std::min(length, newLength); i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        length = newLength;
    }

    void Initialize() {
        for (int i = 0; i < length; i++) {
            std::cin >> data[i]; 
        }
    }

    int Find(int value) {
        for (int i = 0; i < length; i++) {
            if (data[i] == value) {
                return i;
            }
        }
        return -1;
    }

    int FindMax() {
        int max = data[0];
        for (int i = 1; i < length; i++) {
            if (data[i] > max) {
                max = data[i];
            }
        }
        return max;
    }

    int FindMin() {
        int min = data[0];
        for (int i = 1; i < length; i++) {
            if (data[i] < min) {
                min = data[i];
            }
        }
        return min;
    }

    void Merge(DynamicArray& other) {
        int newLength = length + other.length;
        int* newData = new int[newLength];
        for (int i = 0; i < length; i++) {
            newData[i] = data[i];
        }
        for (int i = 0; i < other.length; i++) {
            newData[length + i] = other.data[i];
        }
        delete[] data;
        data = newData;
        length = newLength;
    }

    void BubbleSort() {
        for (int i = 0; i < length - 1; i++) {
            for (int j = 0; j < length - i - 1; j++) {
                if (data[j] > data[j + 1]) {
                    int temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }

    void Print() {
        for (int i = 0; i < length; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    DynamicArray m (3);
    m.Initialize();
    m.Print();
    std::cout << m.FindMax() << " ";
    std::cout << m.FindMin();

    DynamicArray m2 (3);
    m2.Initialize();
    m2.Print();
    m2.Merge(m);
    m2.BubbleSort();
    m2.Print();


    return 0;
}
