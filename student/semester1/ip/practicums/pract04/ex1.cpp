#include <iostream>

int absoluteValue_(int number)
{
    if (number >= 0)
        return number;
    return number - 2 * number;
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << absoluteValue_(n);
}