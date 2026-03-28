#include <iostream>

constexpr size_t ARRAY1_SIZE = 5;
constexpr size_t ARRAY2_SIZE = 6;

bool arrContainsNumber(const int arr[], size_t size, int number)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == number)
        {
            return true;
        }
    }

    return false;
}

void printIntersection(const int arr1[], const int arr2[], size_t arr1Size, size_t arr2Size)
{
    std::cout << '[';

    if (arr1Size > arr2Size)
    {
        for (int i = 0; i < arr2Size; i++)
        {
            if (arrContainsNumber(arr1, arr1Size, arr2[i]))
            {
                std::cout << arr2[i] << ", ";
            }
        }
    }
    else
    {
        for (int i = 0; i < arr1Size; i++)
        {
            if (arrContainsNumber(arr2, arr2Size, arr1[i]))
            {
                std::cout << arr1[i];

                if (i != arr1Size - 2)
                {
                    std::cout << ", ";
                }
            }
        }
    }

    std::cout << ']' << std::endl;
}

void printUnion(const int arr1[], const int arr2[], size_t arr1Size, size_t arr2Size)
{
    std::cout << '[';

    for (int i = 0; i < arr1Size; i++)
    {
        std::cout << arr1[i] << ", ";
    }

    for (int i = 0; i < arr2Size; i++)
    {
        if (!arrContainsNumber(arr1, arr1Size, arr2[i]))
        {
            std::cout << arr2[i];

            if (i != arr2Size - 1)
            {
                std::cout << ", ";
            }
        }
    }

    std::cout << ']' << std::endl;
}

int main()
{
    int arr1[] = {2, 4, 1, 7, 8};
    int arr2[] = {1, 2, 3, 5, 7, 11};

    printIntersection(arr1, arr2, ARRAY1_SIZE, ARRAY2_SIZE);
    printUnion(arr1, arr2, ARRAY1_SIZE, ARRAY2_SIZE);
}