#include <iostream>

int GCD(int n, int k)
{
    if (n < k)
    {
        int temp = n;
        n = k;
        k = temp;
    }

    while (k != 0)
    {
        int mod = n % k;
        n = k;
        k = mod;
    }

    return n;
}

void fractionReduction(int& num, int& denom)
{
    int gcd = GCD(num, denom);
    num /= gcd;
    denom /= gcd;
}

int main()
{
    int a, b;
    std::cin >> a >> b;

    if (b == 0)
    {
        std::cout << "Error! Cannot divide by zero!";
        return 0;
    }

    fractionReduction(a, b);
    std::cout << a << "/" << b;
}