#include <iostream>
#include <iomanip>
using namespace std;

class MyArray {
private:
    int** arr;
    int row;
    int col;

public:
    MyArray(int m, int n) {
        col = n;
        row = m;
        arr = new int*[row];
        for (int i = 0; i < m; ++i) {
            arr[i] = new int[col];
        }
    }

    ~MyArray() {
        for (int i = 0; i < row; ++i) {
            delete[] arr[i];
        }
        delete[] arr;
    }

    void Init() {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                arr[i][j] = col * i + j + 1;
                //cout << "Enter value for [" << i << "][" << j << "]: ";
                //cin >> arr[i][j];
            }
        }
    }

    void search(int i, int j) {
        cout << arr[i][j] << " " << *(arr[i] + j) << endl;
    }

    void print() {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                cout << setw(4) << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    MyArray arr(3,3);
    arr.Init();
    arr.print();
    arr.search(1,1);
}