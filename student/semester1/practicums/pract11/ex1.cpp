#include <iostream>

using namespace std;

constexpr size_t MATRIX_SIZE = 3;

//1. parse matrix to str
//2. findInText for the parsed matrix

bool isPrefix(const char* text, const char* pattern)
{
    while(*text && *pattern && *text == *pattern)
    {
        text++;
        pattern++;
    }

    return !(*pattern);
}

int findInText(const char* text, const char* pattern)
{
    size_t textLen = myStrLen(text);
    size_t textPattern = myStrLen(pattern);
    size_t originalTextLen = myStrLen(text);

    while (textLen >= textPattern)
    {
        text++;
        if (isPrefix(text, pattern))
            return originalTextLen - textLen;
    }

    return -1;
}

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

bool matrixContainsString(const char matrix[][MATRIX_SIZE], const char* text)
{
    unsigned matchingLetters = 0;

    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            if (matrix[i][j] == text[j] || matrix[j][i] == text[j])
                matchingLetters++;
        }
    }

    return matchingLetters == myStrLen(text);
}

int main()
{
    char matrix[MATRIX_SIZE][MATRIX_SIZE] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i' };
    char text[] = { 'a', 'b', 'c' };

    cout << matrixContainsString(matrix, text);
}
