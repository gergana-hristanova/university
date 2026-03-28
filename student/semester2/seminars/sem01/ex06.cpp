#include <iostream>

template <typename T, typename U>
using UnaryFunc = U(*)(T);

template <typename T, typename U>
T* map(UnaryFunc<T, U> f, T* arr, std::size_t size)
{
    for (std::size_t i = 0; i < size; ++i)
    {
        arr[i] = f(arr[i]);
    }

    return arr;
}

int byTwoInt(int x)
{
    return 2 * x;
}

int main()
{
    int arr[4] = { 1, 2, 3, 4 };
    int* res = map<int, int>([](int x){ return 2 * x; }, arr, 4);
    for (std::size_t i = 0; i < 4; ++i)
    {
        std::cout << res[i];
    }
}