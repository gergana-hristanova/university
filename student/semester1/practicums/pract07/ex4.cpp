#include <iostream>

int reverse(int n)
{
    int res = 0;
    while (n)
    {
        (res *= 10) = n % 10;
        n /= 10;
    }

    return res;
}

int decimalToOctal(int n)
{
    int res = 0;
    while (n)
    {
        (res *= 10) += n % 8;
        n /= 8;
    }

    return reverse(res);
}

int main()
{
    std::cout << decimalToOctal(90);
}