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

bool isValidNum(const char* num)
{
    if (strLen(num) != M) return false;

    bool seen[10] = { 0 };
    while(*num)
    {
        if (*num < '0' || *num > '9')
            return false;
        
        size_t asDigit = *num - '0';
        if (seen[asDigit]) return false;

        seen[asDigit] = 1;
        
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
        
        numbers[i][M] = 0; //place terminator after end of digit

        bulls[i] = currBulls;
        cows[i] = currCows;
    }
}

void increment(char* cand)
{
    for (size_t i = M - 1; i >= 0 ; i--)
    {
        if (cand[i] < '9')
            cand[i]++;
        else
        {
            cand[i] = '0';
        }
    }
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

void computePossibleGuesses()
{
    char cand[MAX_LENGTH + 1] = { 0 };

    //initial guess is 012... M digits
    for (size_t i = 0; i < M; i++)
        cand[i] = '0' + i;
    
    cout << cand;
}

int main()
{
    enterGameSettings();

    enterGuesses();

    //printAll();

    computePossibleGuesses();

    cout << "Quitting game...";
}