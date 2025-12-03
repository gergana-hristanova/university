/* EXERCISE:
   Write a function which finds the count of lowercase latin letters in a given string. */

#include <iostream>

constexpr size_t MAX_ARR_SIZE = 1024;

int countLower(const char* s)
{
    unsigned countLower = 0;
    
    // int i = 0;
    // while (s[i] != 0)
    // {
    //     if (s[i] >= 'a' && s[i] <= 'z')
    //     {
    //         countLower++;
    //     }

    //     i++;
    // }

    for (int i = 0; s[i] != 0; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            ++countLower;
    }

    return countLower;
}

int main()
{
    char s[MAX_ARR_SIZE];

    std::cout << "Please insert string: ";
    std::cin.getline(s, MAX_ARR_SIZE - 1); //address, max symbols per line (+ place for \0)

    std::cout << "Count of letters: " << countLower(s) << std::endl;
}