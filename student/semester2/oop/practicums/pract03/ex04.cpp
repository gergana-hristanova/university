#include <iostream>

using std::size_t;

class Matrix
{
    public:

    Matrix(size_t rows, size_t cols)
    : matr(new double[rows + cols]{})
    {}

    void setValue(int row, int col, double value)
    {
        if (row > rows || col > cols)
        {
            std::exit(1);
        }

        matr[row + col] = value;
    }

    double getValue(int row, int col) const
    {
        return matr[row + col];
    }

    double& at(int row, int col) const
    {
        return matr[row + col];
    }

    void print() const
    {
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < cols; j++)
            {
                std::cout << matr[rows + cols] << " ";
            }
            std::cout << std::endl;
        }
    }

    Matrix add(const Matrix& mat1, const Matrix& mat2)
    {
        Matrix res = Matrix(mat1.rows, mat1.cols);
        if (mat1.rows == mat2.rows && mat1.cols == mat2.cols)
        {
            for (size_t i = 0; i < mat1.rows; i++)
            {
                for (size_t j = 0; j < mat1.cols; j++)
                {
                    res.at(i, j) = mat1.at(i, j) + mat2.at(i, j);
                }
            }
        }

        return res;
    }

    ~Matrix()
    {
        delete[] matr;
    }

    private:

    double* matr;
    size_t rows;
    size_t cols;
};

int main()
{
    Matrix mat1(2, 3), mat2(2, 3);

    mat1.setValue(0, 0, 1.0);
    mat1.setValue(0, 1, 2.0);
    mat1.setValue(0, 2, 3.0);
    mat1.setValue(1, 0, 4.0);
    mat1.setValue(1, 1, 5.0);
    mat1.setValue(1, 2, 6.0);

    mat2.setValue(0, 0, 7.0);
    mat2.setValue(0, 1, 8.0);
    mat2.setValue(0, 2, 9.0);
    mat2.setValue(1, 0, 10.0);
    mat2.setValue(1, 1, 11.0);
    mat2.setValue(1, 2, 12.0);

    std::cout << "Matrix 1:" << std::endl;
    mat1.print();

    std::cout << "Matrix 2:" << std::endl;
    mat2.print();

    Matrix sum = Matrix::add(mat1, mat2);
    std::cout << "Sum of matrices:" << std::endl;
    sum.print();

    Matrix identity = Matrix::identity(3);
    std::cout << "Identity matrix of size 3:" << std::endl;
    identity.print();

    return 0;
}