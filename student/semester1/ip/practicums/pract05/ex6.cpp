#include <iostream>

bool isPalindromeArr(const int arr[], size_t size)
{
    for (int i = 0; i < size / 2; i++)
    {
        if (arr[i] != arr[size - i - 1])
            return false;
    }

    return true;
}

int main()
{
    const int size = 8;
    int arr[size] = { 1, 2, 3, 4, 4, 3, 2, 1 };

    std::cout << isPalindromeArr(arr, size);
}