#include <iostream>

int toggleBit(int n, int m)
{
    int mask = 1 << m;
    return n ^ mask;
}

int bitsCount(int x)
{
    int count = 0;
    while (x != 0)
    {
        x /= 2;
        count++;
    }

    return count;
}

int buildNum(int x, int m, int n)
{
    return x >> bitsCount(x) - n;;
}

int main()
{
    //std::cout << buildNum(16, 4, 3); //10000 -> |100|00 -> 100 = 4

    std::cout << buildNum(16, 4, 3);
}