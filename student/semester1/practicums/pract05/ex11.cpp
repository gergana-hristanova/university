#include <iostream>

int getFirstMostCommonDigit(const int arr[], size_t size)
{
    // Count occurences
    int digits[10] = { 0 };
    for (int i = 0; i < size; i++)
    {
        digits[arr[i]]++;
    }

    // Find digit with most occurences (max frequency)
    int maxFreq = digits[0];
    for (int i = 0; i < 9; i++)
    {
        if (digits[i] > maxFreq)
        {
            maxFreq = digits[i];
        }
    }

    // Return first digit in array with maxFreq
    for (int i = 0; i < size; i++)
    {
        if (digits[arr[i]] == maxFreq)
        {
            return arr[i];
        }       
    }

    return -1;
}

int main()
{
    int arr[9] = { 6, 3, 5, 7, 6, 5, 3, 6, 5 };

    std::cout << getFirstMostCommonDigit(arr, 9);
}