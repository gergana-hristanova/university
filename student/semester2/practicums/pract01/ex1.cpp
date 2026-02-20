#include <iostream>

template<typename T>
T sum(T* arr, size_t size)
{
    if (size == 0) return T(); //T() - default value for T
    T result = arr[0];
    for(size_t i = 1; i < size; i++) {
        result += arr[i];
    }

    return result;
}

int main()
{
    int arr[] = { 2, 7, 11 };
    std::cout << sum(arr, 3);
}