#include <iostream>

using namespace std;

void fillArr(int* arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        int currNum;
        cin >> currNum;
        arr[i] = currNum;
    }  
}

size_t getOnesCount(int* mask, size_t size)
{
    size_t onesCount = 0;
    for (size_t i = 0; i < size; i++)
        if (mask[i] == 1)
            onesCount++;

    return onesCount;
}

void fillResult(int* src, int* mask, int* res, size_t srcLen)
{
    size_t resIndex = 0;
    for (size_t i = 0; i < srcLen; i++)
    {
        if (mask[i])
            res[resIndex++] = src[i];
    }
}

void printArr(int* arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
        cout << arr[i] + " ";
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    int* nums = new int[n];
    fillArr(nums, n);

    int* mask = new int[n];
    fillArr(mask, n);

    size_t resLen = getOnesCount(mask, n);
    int* result = new int[resLen];
    fillResult(nums, mask, result, n);

    printArr(nums, n);
    printArr(result, resLen);
}