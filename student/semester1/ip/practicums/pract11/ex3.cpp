#include <iostream>

using namespace std;

void transformStr(char* str)
{
    if (!str) return;

    while (*str)
    {
        if ('A' <= *str && *str <= 'Z')
            *str += 'a' - 'A';
        else if ('a' <= *str && *str <= 'z')
            *str -= 'a' - 'A';
        else if ('1' <= *str && *str <= '9')
            *str = '*';

        str++;
    }
}

int main()
{
    char str[7] = "12ABcd";
    transformStr(str);
    cout << str;
}