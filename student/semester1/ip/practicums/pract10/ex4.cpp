#include <iostream>

void sumRows(const int matrix[][3], size_t size)
{
    std::cout << "Sums of rows: ";

    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = 0; j < size; j++)
        {
            sum += matrix[i][j];
        }
        std::cout << sum << " ";
    }
}

void sumCols(const int matrix[][3], size_t size)
{
    std::cout << "Sums of cols: ";

    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = 0; j < size; j++)
        {
            sum += matrix[j][i];
        }
        std::cout << sum << " ";
    }
}

int main()
{
    int matrix[][3] = { 5, 1, 5, 0, 5, 9, 0, 6, 7 };
    sumRows(matrix, 3);
    sumCols(matrix, 3);
}