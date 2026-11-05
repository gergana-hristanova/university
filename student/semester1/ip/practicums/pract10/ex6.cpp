#include <iostream>

int sumPrimaryDiagonal(const int matrix[][3], size_t size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += matrix[i][i];

    return sum;
}

int sumSecondaryDiagonal(const int matrix[][3], size_t size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += matrix[i][size - i - 1];

    return sum;
}

bool isMagicSquare(const int matrix[][3], size_t size)
{
    int sum = sumPrimaryDiagonal(matrix, size);

    //check sum of secondary diagonal
    if (sum != sumSecondaryDiagonal(matrix, 3))
        return false;

    //check sum of rows
    for (int i = 0; i < size; i++)
    {
        int sumRow = 0;
        for (int j = 0; j < size; j++)
        {
            sumRow += matrix[i][j];
        }
        std::cout << sumRow << " ";
    }
}

int main()
{

}