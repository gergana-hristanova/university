#include <iostream>

const unsigned KEY = 51926;

int encode(int n, int key)
{
    return n ^ key;
}

int main()
{
    int n = 10;
    std::cout << encode(n, KEY) << std::endl;
    std::cout << encode(encode(n, KEY), KEY);
}