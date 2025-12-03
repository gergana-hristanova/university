#include <iostream>

int getSmallestMissing(const int arr[], size_t size)
{
    int left = 0;
    int right = size - 1;
    int base = arr[0];

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == base + mid)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return base + left;
}

int main()
{
    int arr[] = { 5, 6, 7, 9, 10, 12, 13 };
    std::cout << getSmallestMissing(arr, 7);
}