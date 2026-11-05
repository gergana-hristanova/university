#include <iostream>

int getLength(int number)
{
    if (number == 0)
        return 1;

    int count = 0;
    while (number > 0)
    {
        count++;
        number /= 10;
    }

    return count;
}

int main()
{
    std::cout << getLength(123) << std::endl;
    std::cout << getLength(0) << std::endl;
}