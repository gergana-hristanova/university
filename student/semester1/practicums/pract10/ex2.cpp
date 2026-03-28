#include <iostream>

//only for sqaure matrices
void printPrimaryDiagonal(const int matrix[][3], size_t size)
{
    for (size_t i = 0; i < size; i++)
        std::cout << matrix[i][i] << " ";
    std::cout << std::endl;
}

//only for sqaure matrices
void printSecondaryDiagonal(const int matrix[][3], size_t size)
{
    for (size_t i = 0, j = size - 1; i < size && j >= 0; i++, j--)
            std::cout << matrix[i][j] << " ";
    std::cout << std::endl;
}

int main()
{
    int matrix[][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    printPrimaryDiagonal(matrix, 3);
    printSecondaryDiagonal(matrix, 3);
}