#include <iostream>

void getPositiveAndNegativeCount(const int arr[], size_t size)
{
    unsigned positiveCount = 0;
    unsigned negativeCount = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] > 0)
        {
            positiveCount++;
        }
        else if (arr[i] < 0) //must count it separately because there might be zeroes
        {
            negativeCount++;
        }
    }

    std::cout << "positive:" << positiveCount;
    std::cout << "negative:" << negativeCount;

    if (positiveCount > negativeCount)
        std::cout << "The number of positive integers is GREATER than the number of negative integers." << std::endl;
    else if (positiveCount < negativeCount)
        std::cout << "The number of positive integers is SMALLER than the number of negative integers." << std::endl;
    else
        std::cout << "The number of positive and negative integers is EQUAL." << std::endl;
}

int main()
{
    constexpr size_t ARR_SIZE = 10;
    int arr[ARR_SIZE] = { -1, 4, 6, 7, 9, -4, -7, 8, -9, 5 };
    getPositiveAndNegativeCount(arr, ARR_SIZE);
}