#include <iostream>

int countBinaryOnes(int n)
{
    int count = 0;

    //Kernigan algorithm (genius XOXO)
    while (n)
    {
        n &= (n - 1);
        ++count;
    }

    return count;
}

bool isBinaryPermutation(int a, int b)
{
    return countBinaryOnes(a) == countBinaryOnes(b); 
}

int main()
{
    std::cout << isBinaryPermutation(7, 1) << std::endl; //false
    std::cout << isBinaryPermutation(7, 11) << std::endl; //true
}