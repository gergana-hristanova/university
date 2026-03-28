#include <iostream>

// Taken from ex1.cpp
int sumArray(const int arr[], size_t size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum;
}

double averageArray(const int arr[], size_t size)
{
    return sumArray(arr, size) * 1.0 / size;
}

int main()
{
    int arr[4] = { 5, 7, 4, 9 };

    std::cout << averageArray(arr, 4);
}