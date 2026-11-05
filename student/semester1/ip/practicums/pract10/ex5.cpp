#include <iostream>

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void matrixTransposition(int matrix[][3], size_t size)
{
    for (int i = 0; i < size / 2; i++)
    {
        for (int j = 0; j < size; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void printMatrix(const int matrix[][3], size_t size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int matrix[][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    matrixTransposition(matrix, 3);
    printMatrix(matrix, 3);
}