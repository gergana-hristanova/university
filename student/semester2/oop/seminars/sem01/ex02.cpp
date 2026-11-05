#include <iostream>

template <typename T, typename U>
using UnaryFunc = U(*)(T);

template <typename T, typename U, typename S>
auto composition(UnaryFunc<T, U> f, UnaryFunc<U, S> g)
{
    return [f, g](T x){ return  g(f(x)); };
}

int main()
{
    std::cout << composition<int, int, int>([](int x){ return x + 1;}, 
                                            [](int x){ return x * 2;})(5) << '\n'; // -> 12
}