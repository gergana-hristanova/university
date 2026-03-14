#include <iostream>

class Dipper
{
    public:
    Dipper() : currNum(numIterator++) {}

    unsigned getNumber() const
    {
        return this->currNum;
    }

    private:
    static unsigned numIterator;
    unsigned currNum;
};

unsigned Dipper::numIterator = 1;

int main()
{
    Dipper dipper1, dipper2;

    std::cout << dipper1.getNumber() << std::endl; // 1
    std::cout << dipper2.getNumber() << std::endl; // 2

    {
        Dipper dipper3;
        std::cout << dipper3.getNumber() << std::endl; // 3
    }
    Dipper dipper3;
    std::cout << dipper3.getNumber() << std::endl; // 4

    return 0;
}