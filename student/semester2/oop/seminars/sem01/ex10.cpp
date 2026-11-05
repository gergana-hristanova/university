#include <iostream>

template <typename T>
using toBoolFunc = bool(*)(T);

template <typename T>
bool all(toBoolFunc<T> f, T* arr, std::size_t size)
{
    for (std::size_t i = 0; i < size; ++i)
    {
        if (!f(arr[i]))
        {
            return false;
        }
    }

    return true;
}

template <typename T>
bool any(toBoolFunc<T> f, T* arr, std::size_t size)
{
    for (std::size_t i = 0; i < size; ++i)
    {
        if (f(arr[i]))
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int arr[] = {1, 4, 6, 8, 10};

    std::cout << all<int>([](int x){ return x % 2 == 0; }, arr, 5) << std::endl;
    std::cout << any<int>([](int x){ return x % 2 == 0; }, arr, 5);
}