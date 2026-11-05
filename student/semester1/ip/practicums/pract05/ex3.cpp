#include <iostream>

int findMinInArr(const int arr[], size_t size)
{
    int min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    return min;
}

int findMaxInArr(const int arr[], size_t size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

int main()
{
    const int size = 9;
    int arr[size] = { 3, 1, 2, 8, 13, 5, 1, 6, 25 };

    std::cout << findMinInArr(arr, size) << std::endl; //1
    std::cout << findMaxInArr(arr, size) << std::endl; //25
}