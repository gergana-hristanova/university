#include <iostream>

struct Point {
    int x;
    int y;
};

template <typename T>
T max(T* arr, size_t size) {
    if (size == 0) return T();

    T max = arr[0];
    for(size_t i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

int main() {
    //WILL WORK:
    int arr[] = {1, 6, 8, 2};
    std::cout << max(arr, 4);

    // WILL NOT WORK:
    // Point arr[] = { {1, 2}, {3, 4} };
    // std::cout << max(arr, 5);
}