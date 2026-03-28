#include <iostream>

using namespace std;

size_t myStrLen(const char* str)
{
    if (!str) return 0;

    size_t len = 0;
    while (*str)
    {
        str++;
        len++;
    }

    return len;
}

bool isPalindromeDeprecated(const char* str)
{
    bool isPalindrome = true;
    size_t len = myStrLen(str);
    for (int i = 0; i < len / 2 && isPalindrome; i++)
    {
        if (str[i] != str[len - i - 1])
        {
            isPalindrome = false;
        }   
    }

    return isPalindrome;
}

bool isPalindrome(const char* str)
{
    if (!str) return 0;

    const char* strBackward = str + myStrLen(str) - 1;

    while(str != strBackward)
    {
        if (*str != *strBackward)
            return false;

        str++;
        strBackward--;
    }

    return true;
}

int main()
{
    char str[1024] = "peeep";

    cout << isPalindrome(str);
}