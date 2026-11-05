#include <iostream>

int sumArray(const int arr[], size_t size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum;
}

int main()
{
    int arr[4] = { 5, 7, 4, 9 };

    std::cout << sumArray(arr, 4);
}