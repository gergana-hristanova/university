#include <iostream>

void bitwiseSwitch(int& a, int& b)
{
    a ^= b;
    b ^= a;
    a ^= b;
    //... bruh
}

void noTempSwitch(int& a, int& b)
{
    a += b;
    b = a - b;
    a -= b;
}

int main()
{
    int a = 3;
    int b = 600;
    bitwiseSwitch(a, b);
    std::cout << a << std::endl << b;
}