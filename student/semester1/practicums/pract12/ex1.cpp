#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int* nums = new int[n];
    for (size_t i = 0; i < n; i++)
    {
        int currNum;
        cin >> currNum;
        nums[i] = currNum;
    }
    
    int sumOnEvenPlaces = 0;
    for (size_t i = 0; i < n; i += 2)
    {
        sumOnEvenPlaces += nums[i];
    }

    cout << sumOnEvenPlaces;
}