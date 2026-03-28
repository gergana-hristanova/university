#include <iostream>

constexpr size_t ARR1_SIZE = 5;
constexpr size_t ARR2_SIZE = 4;

bool arrContainsInt(const int arr[], size_t size, int n)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == n)
            return true;
    }

    return false;
}

int findMissingFromSecondArr(const int arr1[], const int arr2[], size_t size1, size_t size2)
{
    for (int i = 0; i < size1; i++)
    {
        int currArr1Num = arr1[i];
        if (!arrContainsInt(arr2, size2, arr1[i]))
            return currArr1Num;
    }

    return -1; //will never be reached
}

void insertArr(int arr[], size_t size)
{
    for (int i = 0; i < size; i++)
    {
        int toInsert = 0;
        std::cin >> toInsert;
        arr[i] = toInsert;
    }
}

int main()
{
    int arr1[ARR1_SIZE] = { 0 };
    insertArr(arr1, ARR1_SIZE);
    int arr2[ARR2_SIZE] = { 0 };
    insertArr(arr2, ARR2_SIZE);

    std::cout << findMissingFromSecondArr(arr1, arr2, ARR1_SIZE, ARR2_SIZE);
}