
#include <iostream>

using namespace std;

template <typename T>
class Vector {
private:
    T* data;
    int size;

public:
    Vector() {
        data = nullptr;
        size = 0;
    }

    Vector(int n, T arr[]) {
        size = n;
        data = new T[size]();
        for (int i = 0; i < size; i++)
            data[i] = arr[i];
    }

    Vector(const Vector& other) {
        size = other.size;
        data = new T[size];

        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
    }


    ~Vector() {
        delete[] data;
    }

    void swap(Vector& other) {
        T* tempData = data;
        data = other.data;
        other.data = tempData;

        int tempSize = size;
        size = other.size;
        other.size = tempSize;
    }
    void print() {
        for (int i = 0; i < size; i++) {
            cout << data[i]<< ' ';
        }
        cout << endl;
    }
};

int main() {
    int Arr1[] = { 1, 2, 3, 4, 5 };
    int Arr2[] = { 6, 7, 8, 9, 10 };
    Vector a(5, Arr1);
    Vector b(5, Arr2);
    a.print();
    b.print();

    a.swap(b);

    a.print();
    b.print();

    return 0;
}
