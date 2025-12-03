#include <iostream>

void maxSumArr(int arr[], size_t size)
{
    int maxInd = 0;
    int scndMaxInd = 0;
    int max = arr[0];
    int scndMax = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            maxInd = i;
        }
        else if (arr[i] > scndMax)
        {
            scndMax = arr[i];
            scndMaxInd = i;
        }
    }

    std::cout << maxInd << ", " << scndMaxInd << ", " << max + scndMax;
}

int main()
{
    int arr[] = { 3, 8, 2, 7, 5 };
    maxSumArr(arr, 5);
}