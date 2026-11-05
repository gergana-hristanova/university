#include <iostream>

constexpr size_t BIT_SIZE = 8;

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
    if (sym == 0)
        return 0;
    else if ('0' <= sym && sym <= '9')
        return sym - '0';
    else if ('A' <= sym && sym <= 'Z')
        return 10 + sym - 'A';
    else
        return -1;
}

int fromRandomToDecimal(char from[], size_t size, unsigned base)
{
    int decimal = 0;
    for (int i = size - 1, mult = 1; i >= 0; i--, mult *= base)
    {
        decimal += getIndexFromSymbol(from[i]) * mult;
    }

    return decimal;
}

void fromBase12ToBase13(char from[], char to[])
{
    int decimal = fromRandomToDecimal(from, BIT_SIZE, 12);
    fromDecimalToRandom(decimal, to, BIT_SIZE, 13);
}

void printArr(const char arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
        std::cout << arr[i];
    std::cout << std::endl;
}

int main()
{
    char from[BIT_SIZE] = { 0, 0, 0, 0, '4', '5', 'A', '1' };
    char to[BIT_SIZE] = { 0 };

    fromBase12ToBase13(from, to);

    std::cout << fromRandomToDecimal(from, BIT_SIZE, 12) << std::endl;

    printArr(to, BIT_SIZE);
}