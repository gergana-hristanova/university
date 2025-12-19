#include <iostream>
#include <stdlib.h>

using namespace std;

constexpr size_t MAX_SIZE = 20;
unsigned board[MAX_SIZE][MAX_SIZE] = { 0 };

size_t N = 4; //board size
unsigned K = 11; //win condition

bool hasQuit = false;
bool isPlaying = false;

void clearConsole()
{
    system("clear"); //change to "cls" if on Windows / "clear" if on Linux/MaxOS
}

void printBoard()
{
    clearConsole();

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            cout << "|  " << board[i][j] << "  ";
        }

        cout << "|" << endl;
    }
}

int randFromTo(unsigned from, unsigned to)
{
    return from + rand() % (to - from + 1);
}

void addNewNum()
{
    size_t i = randFromTo(0, N - 1);
    size_t j = randFromTo(0, N - 1);

    if (board[i][j] != 0)
    {
        addNewNum();
        return;
    }
    
    const unsigned probability = randFromTo(1, 10);
    if (probability == 1)
        board[i][j] = 4;
    else
        board[i][j] = 2;
}

void compressRow(unsigned row[])
{
    unsigned result[N] = { 0 };
    size_t posInResult = 0;

    for (size_t i = 0; i < N; i++)
    {
        unsigned curr = row[i];
        if (curr != 0)
        {
            result[posInResult] = curr;
            posInResult++;
        }
    }

    for (size_t i = 0; i < N; i++)
    {
        row[i] = result[i];
    }
}

void mergeInRow(unsigned row[])
{
    for (size_t i = 0; i < N - 1; i++)
    {
        if (row[i] == row[i + 1])
        {
            row[i] *= 2;
            row[i + 1] = 0;
            i++;
        }
    }
}

void reverseRow(unsigned row[])
{
    for (size_t i = 0; i < N / 2; i++)
    {
        swap(row[i], row[N - i - 1]);
    }
}

void transposeBoard() {
    for (size_t i = 0; i < N; i++) {
        for (size_t j = i + 1; j < N; j++) {
            swap(board[i][j], board[j][i]);
        }
    }
}

void processRow(unsigned row[]) {
    compressRow(row);
    mergeInRow(row);
    compressRow(row);
}

void moveLeft() {
    for (size_t i = 0; i < N; i++)
        processRow(board[i]);
}

void moveRight() {
    for (size_t i = 0; i < N; i++) {
        reverseRow(board[i]);
        processRow(board[i]);
        reverseRow(board[i]);
    }
}

void moveUp() {
    transposeBoard();
    moveLeft();
    transposeBoard();
}

void moveDown() {
    transposeBoard();
    moveRight();
    transposeBoard();
}

int strcmp(const char* a, const char* b)
{
    if (!a || !b) return 0;

    while (*a && *a == *b)
    {
        a++;
        b++;
    }

    return *a - *b;
}

bool boardsEqual(unsigned a[][MAX_SIZE], unsigned b[][MAX_SIZE], size_t N) {
    for (size_t i = 0; i < N; i++)
        for (size_t j = 0; j < N; j++)
            if (a[i][j] != b[i][j])
                return false;
    return true;
}

void handleGameInput()
{
    while (true) {
        cout << endl << "Enter left/right/up/down:" << endl;

        char gameInput[16];
        cin >> gameInput;

        unsigned boardCopy[MAX_SIZE][MAX_SIZE];
        for (size_t i = 0; i < N; i++)
            for (size_t j = 0; j < N; j++)
                boardCopy[i][j] = board[i][j];

        if (strcmp(gameInput, "left") == 0)
            moveLeft();
        else if (strcmp(gameInput, "right") == 0)
            moveRight();
        else if (strcmp(gameInput, "up") == 0)
            moveUp();
        else if (strcmp(gameInput, "down") == 0)
            moveDown();

        if (!boardsEqual(board, boardCopy, N))
            addNewNum();

        printBoard();
    }
}

void startGame()
{
    clearConsole();

    size_t i = randFromTo(0, N - 1);
    size_t j = randFromTo(0, N - 1);
    board[i][j] = 2;

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
        cout << "ERROR! Invalid win condition!" << endl;
        cin >> winCond;
    }

    N = boardSize;
    K = winCond;
}

void handleHomescreenInput()
{
    unsigned input;
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
    clearConsole();
    
    cout << "=== WELCOME TO 2048 ===" << endl << "1 - Start Game" << endl << "2 - Settings" << endl << "3 - Quit" << endl;

    handleHomescreenInput();

    if (!hasQuit && !isPlaying)
        homescreen();
}

int main()
{
    srand(time(0)); //neccesary for rand() to work

    homescreen();

    if (!hasQuit)
        startGame();

    cout << "Quitting game...";
}

// Може ли да ползваме функция за четене на цял ред от конзолата за 3 зад? ---да
// Може ли да ползваме srand(time(0)) във 2 зад?
// Може ли да ползваме проверка от вида if(cin >> n) за валидация на входни данни? ---няма нужда, защото при въведен текст и непроверено такова няма да е санкция
// Може ли да имаме вложени цикли при обхождане на матрицата във 2 зад? ---да
// Грешен ли е примерът в 3 зад? ---да, трябва да е 100 вместо 10