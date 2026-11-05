#include <iostream>

//only for square matrices
int getMinPrimaryDiagonal(const int matrix[][3], size_t size)
{
    int min = matrix[0][0];
    for (size_t i = 1; i < size; i++)
    {
        if (matrix[i][i] < min)
            min = matrix[i][i];
    }

    return min;
}

int main()
{
    int matrix[][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::cout << getMinPrimaryDiagonal(matrix, 3);
}