#include <iostream>

constexpr size_t TO_SIZE = 16; //bits

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

void printArr(const char arr[], size_t size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i];
    
    std::cout << std::endl;
}

int main()
{
    char to[TO_SIZE] = { 0 };
    int decimal, base;
    std::cin >> decimal >> base;

    fromDecimalToRandom(decimal, to, TO_SIZE, base);
    printArr(to, TO_SIZE);
}