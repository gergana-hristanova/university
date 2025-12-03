#include <iostream>

void swapInt(int& n1, int& n2)
{
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

void swapDouble(double& n1, double& n2)
{
    double temp = n1;
    n1 = n2;
    n2 = temp;
}

int main()
{
    int a, b;
    std::cin >> a >> b;

    swapInt(a, b);

    std::cout << a << std::endl << b;
}