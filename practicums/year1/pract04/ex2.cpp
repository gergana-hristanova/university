#include <iostream>

bool isDigit(char symbol)
{
    if ('0' <= symbol && symbol <= '9')
        return true;

    return false;
}

bool isLower(char symbol)
{
    if ('a' <= symbol && symbol <= 'z')
        return true;

    return false;
}

bool isUpper(char symbol)
{
    if ('A' <= symbol && symbol <= 'Z')
        return true;

    return false;
}

int main()
{
    char ch;
    std::cin >> ch;
    std::cout << isDigit(ch);

    if (!isDigit(ch))
    {
        if (isLower(ch))
            std::cout << ", lower letter";
        else if(isUpper(ch))
            std::cout << ", upper letter";
    }
}