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

int main()
{
    int decimal = 0; //placeholder
    std::cin >> decimal;

    int binary[BIN_SIZE] = { 0 };

    fromDecimalToBinary(decimal, binary);

    printArr(binary, BIN_SIZE);
}