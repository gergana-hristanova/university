#include <iostream>

void printZigZag(const int matrix[][3], size_t size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int secondCoord = j;
            if (i % 2 != 0)
                secondCoord = size - j - 1;
            
            std::cout << matrix[i][secondCoord] << " ";
        }

        std::cout << std::endl;
    }
}

int main()
{
    int matrix[][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    printZigZag(matrix, 3);
}