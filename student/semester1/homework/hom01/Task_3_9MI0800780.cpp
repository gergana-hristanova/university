#include <iostream>

using namespace std;

bool textSizeIsValid(unsigned N, unsigned M)
{
    return (!(1 <= N && N <= 100) || !(50 <= M && M <= 1024));
}

int main()
{
    unsigned N, M; //max rows and max symbols per row
    cin >> N >> M;

    if (!textSizeIsValid)
    {
        cout << "ERROR! Text size is invalid!";
        return -1;
    }

    char text[N][M];

    string inputWord = "";
    while (inputWord != "$end$")
    {
        cin >> inputWord;

        cout << inputWord << "!!!!!!!" << endl;
    }
}