#include <iostream>

constexpr size_t BIN_SIZE = 16;

void fromDecimalToRandom(int dec, int res[], int resBase, size_t size, int& used)
{
    used = 0;

    for (int i = size - 1; i >= 0; i--)
    {
        int current = dec % resBase;
        res[i] = current;
        used++;

        dec /= resBase;
    }
}

void reverseArr(int arr[], size_t size)
{
    for (int i = 0; i < size / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp; 
    }
}

bool isPalindromeArr(const int arr[], size_t size)
{
    for (int i = 0; i < size / 2; i++)
    {
        if (arr[i] != arr[size - i - 1])
            return false;
    }

    return true;
}

int main()
{
    int n;
    std::cin >> n;

    int used = 0;

    int binary[BIN_SIZE] = { 0 };
    fromDecimalToRandom(n, binary, 2, BIN_SIZE, used);
    reverseArr(binary, BIN_SIZE);

    std::cout << isPalindromeArr(binary, used);
}