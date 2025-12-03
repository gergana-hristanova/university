#include <iostream>

void reverseArr(int arr[], size_t size)
{
    for (int i = 0; i < size / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

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
    const int size = 7;
    int arr[size] = { 1, 7, 4, -5, 12, -3, 6 };

    reverseArr(arr, size);
    printArr(arr, size);
}