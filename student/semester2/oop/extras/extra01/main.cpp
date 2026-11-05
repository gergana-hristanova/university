#include <iostream>
#include "triangle.hpp"

int main()
{
    Triangle t1 = Triangle();
    Triangle t2 = Triangle(5, 7, 9);

    t1.printInfo();
    std::cout << t1.getPerimeter() << std::endl;
    std::cout << t1.getArea() << std::endl;
    t2.printInfo();
}