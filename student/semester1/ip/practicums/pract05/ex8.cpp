#include <iostream>

void sortEvenAndUneven(int arr[], size_t size)
{
    for(int i = size / 2; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            int temp = arr[i - size / 2];
            arr[i - size / 2] = arr[i];
            arr[i] = temp;
        }
    }

    for(int i = 0; i < size / 2; i++)
    {
        if (arr[i] % 2 != 0)
        {
            int temp = arr[i];
            arr[i] = arr[i + size / 2];
            arr[i + size / 2] = temp;
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
    const int size = 7;
    int arr[size] = { 1, 4, 3, 5, 6, -8, 10 };

    sortEvenAndUneven(arr, size);
    printArr(arr, size);
}