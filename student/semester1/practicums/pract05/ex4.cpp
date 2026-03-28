#include <iostream>

bool isSortedAscending(const int arr[], size_t size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            return false;
    }

    return true;
}

int main()
{
    const int size = 4;
    int arr[size] = { 5, 7, 4, 9 };
    int arrSorted[size] = { 1, 2, 3, 4};

    std::cout << isSortedAscending(arr, size) << std::endl;
    std::cout << isSortedAscending(arrSorted, size);
}