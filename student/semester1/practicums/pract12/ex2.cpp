#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int* nums = new int[n];
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int currNum;
        cin >> currNum;
        if (currNum % 2 == 0)
            nums[left++] = currNum;
        else
            nums[right--] = currNum;
    }

    for (size_t i = 0; i < n; i++)
        cout << nums[i];

    delete[] nums;
}