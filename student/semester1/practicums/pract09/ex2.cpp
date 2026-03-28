#include <iostream>

int bitAt(int n, int m)
{
    int mask = 1 << m;
    return n & mask;
}

int main()
{
    std::cout << bitAt(9, 2);
}