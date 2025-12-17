#include <iostream>
#include <stdlib.h>

// TODO: Figure out stack overfow when entering symbol(s) instead of int.
// TODO: WRITE STRCMP and use it instead of ==

using namespace std;

constexpr size_t MAX_SIZE = 20;
unsigned board[MAX_SIZE][MAX_SIZE] = { 0 };

size_t N = 4; //default board size
unsigned K = 11; //default win condition

bool isPlaying = false;
bool hasQuit = false;


void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void clearConsole()
{
    system("clear"); //change to "cls" if on Windows / "clear" if on Linux/MaxOS
}

void printBoard()
{
    clearConsole();

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << "| " << board[i][j] << " ";
        }

        cout << "|" << endl;
    }
}

int randFromTo(unsigned from, unsigned to)
{
    srand(time(0)); //neccesary for rand() to work

    return from + rand() % (to - from + 1);
}

void moveLeft()
{

}

void handleGameInput()
{
    cout << endl << "Enter left/right/up/down:" << endl;

    string gameInput;
    cin >> gameInput;

    if (gameInput == "left")
        moveLeft();

    printBoard();
}

void startGame()
{
    clearConsole();

    board[randFromTo(0, N - 1)][0, N - 1] = 2;

    printBoard();

    handleGameInput();
}

void adjustSettings()
{
    clearConsole();
    
    cout << "=== SETTINGS ===" << endl;

    cout << "Enter board size (currently " << N << "):" << endl;
    size_t boardSize;
    cin >> boardSize;
    while (!(3 <= boardSize && boardSize <= 20))
    {
        cout << "Invalid board size! Enter again:" << endl;
        cin >> boardSize;
    }

    cout << "Enter win condition (currently " << K << "):" << endl;
    unsigned winCond;
    cin >> winCond;
    while (!(4 <= winCond && winCond <= 31))
    {
        cout << "ERROR! Invalid board size!" << endl;
        cin >> boardSize;
    }

    N = boardSize;
    K = winCond;
}

void handleHomescreenInput()
{
    int input;
    cin >> input;

    switch (input)
    {
        case 1:
            isPlaying = true;
            break;

        case 2:
            adjustSettings();
            break;

        case 3:
            hasQuit = true;
            break;
    }
}

void homescreen()
{
    // NE PREDAVAI PRAZEN MAIN

    clearConsole();
    
    cout << "=== WELCOME TO 2048 ===" << endl << "1 - Start Game" << endl << "2 - Settings" << endl << "3 - Quit" << endl;

    handleHomescreenInput();

    if (!hasQuit && !isPlaying)
        homescreen();
}

int main()
{
    homescreen();

    startGame();

    cout << "Quitting game...";
}




// Може ли да ползваме функция за четене на цял ред от конзолата за 3 зад? ---да
// Може ли да ползваме srand(time(0)) във 2 зад?
// Може ли да ползваме проверка от вида if(cin >> n) за валидация на входни данни? ---няма нужда, защото при въведен текст и непроверено такова няма да е санкция
// Може ли да имаме вложени цикли при обхождане на матрицата във 2 зад? ---да
// Грешен ли е примерът в 3 зад? ---да, трябва да е 100 вместо 10