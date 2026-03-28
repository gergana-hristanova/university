#include <iostream>

template <typename T>
using TFunction = bool(*)(T);

template <typename T>
T* filter(const T* arr, size_t size, TFunction<T> f, size_t &retSize) {
    retSize = 0;
    for (size_t i = 0; i < size; i++) {
        if (f(arr[i])) {
            retSize++;
        }
    }

    T* ret = new T[retSize];
    size_t retIndex = 0;
    for (size_t i = 0; i < size; i++) {
        if (f(arr[i])) {
            ret[retIndex++] = arr[i];
        }
    }

    return ret;
}

bool isEven(int n) {
    return n % 2 == 0;
}

//from ex0.cpp for printing result
template<typename T>
void print(const T* arr, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << ' ';
    }

    std::cout << std::endl;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6 };
    size_t retSize;

    int* returned = filter(arr, 6, isEven, retSize);
    print(returned, retSize);
    delete[] returned;
}