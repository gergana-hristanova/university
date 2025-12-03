#include <iostream>

void removeAtPosition(int arr[], size_t size, unsigned pos)
{
    for(int i = pos; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    arr[size - 1] = -1;

    for (int i = 0; i < size; i++)
        std::cout << arr[i] + " ";
}

int main()
{
    const int size = 7;
    int arr[size] = { 0, 1, 2, 3, 4, 5, 6 };

    removeAtPosition(arr, size, 4);
}