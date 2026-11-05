#include <iostream>

template <typename T>
using UnaryFunc = T(*)(T);

template <typename T>
auto repeat(UnaryFunc<T> f, unsigned n)
{
    return [f, n](T x)
    {
        T result = x;
        for (unsigned i = 0; i < n; i++)
        {
            result = f(result);
        }
        return result;
    };
}

template <typename T>
T byTwo(T x)
{
    return 2 * x;
}

int main()
{
    int x = 5;
    std::cout << repeat(byTwo<int>, 3)(x);
}