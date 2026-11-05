#include <iostream>

template<typename T>
unsigned count_elements_above_zero(T* arr, size_t size) {
    unsigned result = 0;
    for (size_t i = 0; i < size; i++) {
        if (arr[i] > 0) {
            ++result;
        }
    }

    return result;
}

int main() {
    int arr[] = { 1, 0, 2, -3, 3 };
    std::cout << count_elements_above_zero(arr, 5);
}