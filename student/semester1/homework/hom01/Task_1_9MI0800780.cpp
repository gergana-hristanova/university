#include <iostream>

using namespace std;

const size_t MAX_LENGTH = 6;
const size_t MAX_GUESSES = 32;

size_t M;
unsigned N;

char numbers[MAX_GUESSES][MAX_LENGTH + 1];
unsigned bulls[MAX_GUESSES] = { 0 };
unsigned cows[MAX_GUESSES] = { 0 };

void printAll()
{
    for (size_t i = 0; i < N; i++)
    {
        cout << numbers[i] << " - " << bulls[i] << " - " << cows[i] << endl;
    }
}

bool isValidLength()
{
    return (1 <= M && M <= MAX_LENGTH);
}

size_t strLen(const char* str)
{
    if (!str) return 0;

    size_t len = 0;
    while (*str)
    {
        len++;
        str++;
    }

    return len;
}

bool hasUniqueDigits(const char* num)
{
    bool seen[10] = { 0 };
    for (size_t i = 0; i < M; i++)
    {
        int currDigit = num[i] - '0';

        if (seen[currDigit])
            return false;

        seen[currDigit] = 1;
    }

    return true;
}

bool isValidNum(const char* num)
{
    if (strLen(num) != M) return false;

    if (!hasUniqueDigits(num)) return false;

    while(*num)
    {
        if (*num < '0' || *num > '9')
            return false;
        
        num++;
    }

    return true;
}

void enterGameSettings()
{
    cout << "=== REVERSE BULLS AND COWS ===" << endl;

    cout << "Enter number length:" << endl;
    cin >> M;
    while (!isValidLength())
    {
        cout << "Number length must be [1..." << MAX_LENGTH << "]. Enter again:" << endl;
        cin >> M;
    }

    cout << "Enter number of guesses:" << endl;
    cin >> N;
}

void enterGuesses()
{
    cout << "Enter guesses (<number> <bulls> <cows>):" << endl;
    for (size_t i = 0; i < N; i++)
    {
        char num[MAX_LENGTH + 1];
        cin >> num;
        
        if (!isValidNum(num))
        {
            cout << "ERROR! Invalid number entered!" << endl;
            return;
        }

        unsigned currBulls;
        cin >> currBulls;

        unsigned currCows;
        cin >> currCows;

        for (size_t j = 0; j < M; j++)
            numbers[i][j] = num[j];
        
        numbers[i][M] = 0;

        bulls[i] = currBulls;
        cows[i] = currCows;
    }
}

bool incrementCand(char* cand)
{
    for (size_t i = 0; i < M; i++)
    {
        //had to use forward-going for because M is size_t and turns i into size_t (and casting is not studied yet)
        size_t index = M - i - 1;

        if (cand[index] < '9')
        {
            cand[index]++;
            return true;
        }

        cand[index] = '0';
    }

    return false;
}

void getBullsAndCowsOfCand(const char* cand, const char* guess, unsigned &bulls, unsigned &cows)
{
    bulls = 0;
    cows = 0;

    bool seen[10] = { 0 };
    for (size_t i = 0; i < M; i++)
    {
        seen[guess[i] - '0'] = true;
    }

    for (size_t i = 0; i < M; i++)
    {
        if (cand[i] == guess[i])
            bulls++;
        else
        {
            unsigned digit = cand[i] - '0';
            if (seen[digit])
            cows++;
        }
    }
}

bool matchesAll(const char* cand)
{
    for (size_t i = 0; i < N; i++)
    {
        unsigned candBulls = 0;
        unsigned candCows = 0;
        getBullsAndCowsOfCand(cand, numbers[i], candBulls, candCows);

        if (candBulls != bulls[i] || candCows != cows[i])
            return false;
    }

    return true;
}

void computePossibleGuesses()
{
    char cand[MAX_LENGTH + 1] = { 0 };

    for (size_t i = 0; i < M; i++)
        cand[i] = '0' + i;

    cout << "Possible numbers:" << endl;

    while (true)
    {
        if (hasUniqueDigits(cand) && matchesAll(cand))
            cout << cand << endl;

        if (!incrementCand(cand))
            break;
    }
}

int main()
{
    enterGameSettings();

    enterGuesses();

    computePossibleGuesses();

    cout << "Quitting game...";
}