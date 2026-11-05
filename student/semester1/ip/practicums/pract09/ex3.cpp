#include <iostream>

int toggleBit(int n, int m)
{
    int mask = 1 << m;
    return n ^ mask;
}

int main()
{
    std::cout << toggleBit(4, 0);
}