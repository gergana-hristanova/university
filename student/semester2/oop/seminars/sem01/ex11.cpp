#include <iostream>
#include <functional>

template <typename T>
//using CmpFunc = int(*)(T, T);
using CmpFunc = std::function<int(T, T)>;

template <typename T>
void sort_by(T* arr, std::size_t size, CmpFunc<T> f)
{
    for (std::size_t i = 0; i < size - 1; ++i)
    {
        for (std::size_t j = i + 1; j < size; ++j)
        {
            if (f(arr[i], arr[j]) > 0)
            {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

int main()
{
    int arr[] = { 1, 5, 3, 2, 4 };

    sort_by<int>(arr, 5, [](int x, int y)
                            {
                                if (x < y) return -1;
                                if (x == y) return 0;
                                return 1;
                            });

    for (std::size_t i = 0; i < 5; ++i)
    {
        std::cout << arr[i] << " ";
    }
}