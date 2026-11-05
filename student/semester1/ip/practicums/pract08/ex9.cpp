#include <iostream>

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int arr[], size_t size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void printArr(const int arr[], size_t size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    
    std::cout << std::endl;
}

int main()
{
    int arr[] = { 15, 3, 6, 3, 1 };
    bubbleSort(arr, 5);

    printArr(arr, 5);
}