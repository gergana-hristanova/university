#include <iostream>

constexpr size_t BINARY_SIZE = 16;

void decimalToRandom(int decimal, bool to[], size_t toSize, unsigned base)
{
    for (int i = toSize - 1; decimal; i--)
    {
        to[i] = decimal % base;
        decimal /= base;
    }
}

unsigned countBits(const bool binary[], size_t size)
{
    unsigned leadingZerosCount = 0;
    for (int i = 0; binary[i] == 0; i++)
        ++leadingZerosCount;
    
    return size - leadingZerosCount;
}

bool isPalindromeBinary(const bool binary[], size_t size)
{
    unsigned bits = countBits(binary, size);

    for (int i = size - bits, j = 0; i < size; i++, j++)
        if (binary[i] != binary[size - j - 1])
            return false;
    
    return true;
}

int main()
{
    bool binary[BINARY_SIZE] = { 0 };
    int decimal = 10;
    
    decimalToRandom(decimal, binary, BINARY_SIZE, 2);
    std::cout << isPalindromeBinary(binary, BINARY_SIZE);
}