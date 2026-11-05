#include <iostream>

template<typename T>
void print(const T* arr, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << ' ';
    }

    std::cout << std::endl;
}

int main() {
    int arr[] = { 1, 2, 3, 4 };
    print(arr, 4);
}