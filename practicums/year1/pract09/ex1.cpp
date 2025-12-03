#include <iostream>

unsigned powerTwo(unsigned k)
{
    return 1 << k;
}

int main()
{
    std::cout << powerTwo(4);
}