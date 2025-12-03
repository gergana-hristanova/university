#include <iostream>

constexpr size_t BINARY_SIZE = 8;

void decimalToRandom(int decimal, bool to[], size_t toSize, unsigned base)
{
    for (int i = toSize - 1; decimal; i--)
    {
        to[i] = decimal % base;
        decimal /= base;
    }
}

void printArr(const bool arr[], size_t size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i];
    
    std::cout << std::endl;
}

void xorBinary(int n1, int n2)
{
    bool bin1[BINARY_SIZE] = { 0 };
    bool bin2[BINARY_SIZE] = { 0 };

    decimalToRandom(n1, bin1, BINARY_SIZE, 2);
    decimalToRandom(n2, bin2, BINARY_SIZE, 2);

    bool result[BINARY_SIZE] = { 0 };
    for (int i = 0; i < BINARY_SIZE; i++)
    {
        if (bin1[i] == bin2[i])
            result[i] = 0;
        else
            result[i] = 1;
    }

    printArr(result, BINARY_SIZE);
}

int main()
{
    xorBinary(7, 11);
}