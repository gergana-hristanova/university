#include <iostream>
#include <cmath>
#include "triangle.hpp"

Triangle::Triangle() : sideA(3), sideB(4), sideC(5) { }

Triangle::Triangle(double a, double b, double c) : Triangle()
{
    if (a > 0 && b > 0 && c > 0)
    {
        sideA = a;
        sideB = b;
        sideC = c;
    }
}

double Triangle::getPerimeter()
{
    return sideA + sideB + sideC;
}

double Triangle::getArea()
{
    double s = getPerimeter() / 2;
    return std::sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}

void Triangle::printInfo()
{
    std::cout << "Side A = " << sideA << std::endl << "Side B = " << sideB << std::endl << "Side C = " << sideC << std::endl;
}