#include <iostream>

constexpr size_t BIT_SIZE = 32;

char getSymbolFromIndex(int n)
{
    if (0 <= n && n <= 9)
        return n + '0';
    else if (10 <= n)
        return n - 10 + 'A';
    else
        return -1;
}

void fromDecimalToRandom(int decimal, char to[], size_t size, unsigned base)
{
    for (int i = size - 1; decimal; i--)
    {
        to[i] = getSymbolFromIndex(decimal % base);
        decimal /= base;
    }
}

int getIndexFromSymbol(char sym)
{
    if ('0' <= sym <= '9')
        return sym - '0';
    else if ('A' <= sym && sym <= 'Z')
        return 10 + sym - 'A';
}

int fromRandomToDecimal(char from[], size_t size, int to, unsigned base)
{
    int decimal = 0;
    for (int i = size - 1, mult = 1; i >= 0; i--, mult *= base)
    {
        decimal += from[i] * mult;
    }

    return decimal;
}

int main()
{
    char from[32] = { 0 };
}