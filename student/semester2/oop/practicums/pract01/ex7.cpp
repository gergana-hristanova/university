#include <iostream>

using CompareFunction = bool(*)(int, int);

//from ex0.cpp
template<typename T>
void print(const T* arr, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << ' ';
    }

    std::cout << std::endl;
}

//selection sort
void sort(int* arr, size_t size, CompareFunction f)
{
    for (size_t i = 0; i < size; i++) {
        for (size_t j = i + 1; j < size; j++) {
            if (f(arr[j], arr[i])) {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

int main() {
    int arr[] = { 1, -7, 8, 2, 3 };
    sort(arr, 5, [](int a, int b){ return a < b; });
    print(arr, 5);
}