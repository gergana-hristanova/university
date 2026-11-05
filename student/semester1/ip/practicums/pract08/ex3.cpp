#include <iostream>


// recursion for the win
int findFibonacci(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;

    return findFibonacci(n - 1) + findFibonacci(n - 2);
}

void printFibonacci(int n)
{
    for (int i = 0; i < n; i++)
        std::cout << findFibonacci(i) << " ";
    
    std::cout << std::endl;
}

int main()
{
    printFibonacci(10);
}