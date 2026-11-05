#include <iostream>

using namespace std;

size_t myStrLen(char* str)
{
    size_t len = 0;
    while (*str)
    {
        len++;
        str++;
    }

    return len;
}

char* getLongestSharedPrefix(char* str1, char* str2)
{
    if (!str1 || !str2) return nullptr;

    char* res = new char[myStrLen(str1)]; //we assume str1 and str2 are of the same length
    size_t resPos = 0;
    while (*str1 && *str2)
    {
        if (*str1 == *str2)
            res[resPos] = *str1;

        str1++;
        str2++;
    }

    return res;
}

int main()
{
    int n;
    cin >> n;

    char* str1 = new char[n + 1];
    cin >> str1;

    char* str2 = new char[n + 1];
    cin >> str2;

    cout << getLongestSharedPrefix(str1, str2);

    delete[] str1;
    delete[] str2;
}