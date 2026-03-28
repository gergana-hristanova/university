#include <iostream>

int reverse(int n)
{
    int res = 0;
    while (n)
    {
        (res *= 10) += n % 10;
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

int ternaryToDecimal(int n)
{
    int decimal = 0;
    unsigned mult = 1;
    while (n)
    {
        decimal += (n % 10) * mult;
        mult *= 3;

        n /= 10;
    }

    return decimal;
}

int ternaryToOctal(int n)
{
    return decimalToOctal(ternaryToDecimal(n));
}

int main()
{
    std::cout << ternaryToOctal(11120); //173
}