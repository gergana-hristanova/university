#include <iostream>

bool hasRepeatingDigits(int num)
{
    int digits[10] = { 0 };

    while (num != 0)
    {
        int lastDigit = num % 10;
        ++digits[lastDigit];

        num /= 10;
    }

    for (int i = 0; i < 10; i++)
        if (digits[i] > 1)
            return true;

    return false;
}

int main()
{
    int num;
    std::cin >> num;

    std::cout << !hasRepeatingDigits(num);
}