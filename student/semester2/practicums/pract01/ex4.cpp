#include <iostream>

// from ex0.cpp for printing end result
template<typename T>
void print(const T* arr, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << ' ';
    }

    std::cout << std::endl;
}

template<typename T>
T* filterMoreThan(T* arr, size_t size, T k, size_t& resSize) {
    resSize = 0;
    for (size_t i = 0; i < size; i++)
        if (arr[i] > k)
            resSize++;
    
    T* result = new T[resSize];
    size_t resIndex = 0;
    for (size_t i = 0; i < size; i++) {
        if (arr[i] > k) { //mira is the best <3
            result[resIndex++] = arr[i];
        }
    }

    return result;
}

int main() {
	float arr3[] = {-2, 1, 3, -1, 3, -10};
	size_t filteredSize;
	float *filtered = filterMoreThan(arr3, 6, -1.f, filteredSize);
	print(filtered, filteredSize);

    delete[] filtered;
}