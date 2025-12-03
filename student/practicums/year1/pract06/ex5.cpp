#include <iostream>

bool isValidInput(int n, int i, int j)
{
    return n >= j && j >= i && i > 0;
}

int reverse(int n)
{
    int reversedN = 0;
    while (n != 0)
    {
        (reversedN *= 10) += n % 10;
        n /= 10;
    }
        
    return reversedN;
}

int getIntLength(int n)
{
    int length = 0;
    while (n != 0)
    {
        length++;
        n /= 10;
    }

    return length;
}

void reduceNumberBetweenIandJ(int& n, int i, int j)
{
    int numsToRemoveFromEnd = getIntLength(n) - j; //12345
    
    for (int k = 0; k < numsToRemoveFromEnd; k++)
        n/= 10;

    n = reverse(n);
    for (int k = 0; k < i - 1; k++)
        n/= 10;
    
    n = reverse(n);
}

int main()
{
    int n, i, j;
    std::cin >> n >> i >> j;

    if (!isValidInput(n, i, j))
    {
        std::cout << "Error! Input must be as follows: n >= j and j >= i and i > 0";
        return 0;
    }

    reduceNumberBetweenIandJ(n, i, j);
    
    std:: cout << n << std::endl;
}