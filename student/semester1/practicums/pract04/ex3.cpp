#include <iostream>

char toLower(char symbol)
{
    return symbol + ('a' - 'A');
}

char toUpper(char symbol)
{
    return symbol - ('a' - 'A');
}

int main()
{
    char ch;
    std::cin >> ch;

    bool isLetter = ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z');

    if (!isLetter)
    {
        std::cout << "Symbol must be a letter!";
    }
    else
    {
        std::cout << toLower(ch) << std::endl << toUpper(ch);
    }
}