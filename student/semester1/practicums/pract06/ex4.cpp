#include <iostream>

int reverse(int n)
{
    int reversedN = 0;
    while (n != 0)
    {
        (reversedN *= 10) += n % 10;
        n /= 10;
    }
        
    return reversedN;
}

void swapKthDigit(int& m, int& n, int k)
{
    --k; //so can can work with the indeces

    m = reverse(m);
    n = reverse(n);

    int mCopy = m;
    int nCopy = n;

    for (int i = 0; i < k; i++)
    {
        m /= 10;
        n /= 10;
    }

    //swap
    int temp = m % 10;
    m /= 10;
    (m *= 10) += n % 10;
    n /= 10;
    (n *= 10) += temp;

    //restore original numbers
    for (int i = 0; i < k; i++)
    {
        (m *= 10) += mCopy % 10;
        mCopy /= 10;
        (n *= 10) += nCopy % 10;
        nCopy /= 10;
    }

    m = reverse(m);
    n = reverse(n);

    //print results
    std::cout << m << std::endl << n;
}

int main()
{
    //hard-coded for ease of testing... sorry
    int a = 1234;
    int b = 6789;
    swapKthDigit(a, b, 2);
}