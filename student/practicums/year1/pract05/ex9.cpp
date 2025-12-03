#include <iostream>

constexpr size_t MAX_ARR_SIZE = 5;

void incrementArr(int arr[], size_t size)
{
    ++arr[size - 1];

    for (int i = size - 1; i > 0; i--)
    {
        if (arr[i] == 10)
        {
            arr[i] = 0;
            ++arr[i - 1];
        }
    }
}

// Taken from ex7.cpp
void printArr(const int arr[], size_t size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

int main()
{
    int arr[MAX_ARR_SIZE] = {0, 1, 0, 0, 9};

    incrementArr(arr, MAX_ARR_SIZE);
    printArr(arr, MAX_ARR_SIZE);
}