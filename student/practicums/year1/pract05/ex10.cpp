#include <iostream>

constexpr size_t MAX_ARR_SIZE = 9;

bool containsDigit(int num, int digit)
{
    while (num > 0)
    {
        int currDigit = num % 10;

        if (digit == currDigit)
            return true;

        num /= 10;
    }

    return false;
}

void zeroElementsNotContainingIndex(int arr[], size_t size)
{
    for (int i = 0; i < size; i++)
    {
        if (!containsDigit(arr[i], i))
        {
            arr[i] = 0;
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
    int arr[MAX_ARR_SIZE] = { 45, 62, 23, 47, 47, 65, 100 };

    zeroElementsNotContainingIndex(arr, MAX_ARR_SIZE);
    printArr(arr, MAX_ARR_SIZE);
}