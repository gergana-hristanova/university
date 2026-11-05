//modified version of ex1.cpp with added countOnes function

#include <iostream>

constexpr unsigned BIN_SIZE = 32; //32 bits

void fromDecimalToBinary(int decimal, int binary[])
{
    int pos = BIN_SIZE - 1;
    while (decimal != 0 && pos >= 0)
    {
        int remainder = decimal % 2;

        binary[pos] = remainder;
        pos--;

        decimal /= 2;
    }
}

void printArr(const int arr[], size_t size)
{
    for (int i = 0; i < size; i++)
        std:: cout << arr[i] << " ";

    std::cout << std::endl;
}

int countOnes(int binary[])
{
    int countOnes = 0;
    for (int i = 0; i < BIN_SIZE; i++)
        if (binary[i] == 1)
            countOnes++;

    return countOnes;
}

int main()
{
    int decimal = 0;
    std::cin >> decimal;

    int binary[BIN_SIZE] = { 0 };

    fromDecimalToBinary(decimal, binary);

    std::cout << countOnes(binary) << std::endl;
}