#include <iostream>

constexpr int ARR_SIZE = 20;

void printNumberFrequencies(const int arr[], size_t size)
{
    constexpr int MAX_NUM_VALUE = 20;
    int numbers[MAX_NUM_VALUE] = { 0 };

    // Counting number occurences
    for (int i = 0; i < ARR_SIZE; i++)
    {
        numbers[arr[i]]++;
    }

    // Printing results
    std::cout << "Number -> Frequency" << std::endl;
    for (int i = 0; i < MAX_NUM_VALUE; i++)
    {
        std::cout << i << " -> " << numbers[i] << std::endl;
    }
}

int main()
{
    int arr[ARR_SIZE] = { 0, 2, 1, 4, 6, 5, 8, 7, 10, 9, 12, 11, 14, 13, 16, 15, 18, 17, 20, 19 };

    printNumberFrequencies(arr, ARR_SIZE);
}