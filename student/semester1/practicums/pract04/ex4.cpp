#include <iostream>

int toNumber(char symbol)
{
    return symbol - '0';
}

char toCharacter(char number)
{
    return number + '0';
}

int main()
{
    std::cout << toNumber('1') << std::endl;
    std::cout << toCharacter(3) << std::endl;
}