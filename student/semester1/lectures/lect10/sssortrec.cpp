#include <iostream>

size_t findMinIndex(const int arr[], size_t size) //not working
{
    if (size == 1)
        return 0;

    int minRest = findMinIndex(arr, size - 1);

    if(arr[size - 1] < minRest)
        return size - 1;
    else
        return minRest;
}

void ssSortRec(int arr[], size_t size)
{
    if (size <= 1) return;

    size_t minIndex = findMinIndex(arr, size);
    
    std::swap(arr[0], arr[minIndex]);

    ssSortRec(arr + 1, size - 1);
}

void printArr(const int arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main()
{
    int arr[] = { 5, 2, 3, 7, 8, 1 };
    ssSortRec(arr, 6);

    printArr(arr, 6);
}