#include <iostream>

using namespace std;

bool isLowerLetter(char ch)
{
    return 'a' <= ch && ch <= 'z';
}

bool contains(const char* str, char ch)
{
    if (!str) return false;

    while (*str)
    {
        if (*str == ch)
            return true;
        
        str++;
    }

    return false;
}

bool allLettersAreUnique(const char* str)
{
    if (!str) return false;

    while (*str)
    {
        if (isLowerLetter(*str))
        {
            if (contains(str + 1, *str))
                return false;
        }

        str++;
    }

    return true;
}

int main()
{
    cout << allLettersAreUnique("sijge");
}