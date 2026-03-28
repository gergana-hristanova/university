#include <iostream>
#include <cmath>

class Complex
{
    public:
    Complex(int re, int im) : re(re), im(im) { }

    Complex operator+(Complex& other)
    {
        return Complex(re + other.re, im + other.im);
    }

    Complex operator-(Complex& other)
    {
        return Complex(re - other.re, im - other.im);
    }

    //(a + bi)(c + di) = (ac − bd) + (ad + bc)i
    Complex operator*(Complex& other)
    {
        return Complex(re * other.re - im * other.im, re * other.im + im * other.re);
    }

    //(a + bi) / (c + di) = [(a + bi)(c - di)] / (c² + d²)
    Complex operator/(Complex& other)
    {
        return other; // not bothering with that logic
    }

    Complex& operator+=(Complex& other)
    {
        *this = *this + other;
        return *this;
    }

    void printAlgebraic()
    {
        if (re == 0)
        {
            if (im == 0)
            {
                std::cout << 0;
            }
            else
            {
                std::cout << im << "i";
            }
        }
        else
        {
            if (im == 0)
            {
                std::cout << re;
            }
            else if (im < 0)
            {
                std::cout << re << im << "i";
            }
            else
            {
                std::cout << re << "+" << im << "i";
            }
        }

        std::cout << std::endl;
    }

    void printTrigonometric()
    {
        double arg = argument();
        std::cout << modulus() << "(cos(" << arg << ") + isin(" << arg << "))" << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex& c)
    {
        if (c.re == 0)
        {
            if (c.im == 0)
            {
                os << 0;
            }
            else
            {
                os << c.im << "i";
            }
        }
        else
        {
            if (c.im == 0)
            {
                os << c.re;
            }
            else if (c.im < 0)
            {
                os << c.re << c.im << "i";
            }
            else
            {
                os << c.re << "+" << c.im << "i";
            }
        }

        return os << std::endl;
    }

    operator double()
    {
        return modulus();
    }

    double operator*()
    {
        return modulus();
    }

    bool operator==(Complex& other) const
    {
        return re == other.re && im == other.im;
    }

    bool operator!=(Complex& other) const
    {
        return !(*this == other);
    }

    friend std::istream& operator>>(std::istream& is, Complex& c)
    {
        return is >> c.re >> c.im;
    }

    private:
    double argument()
    {
        return round(atan2(im, re) * 100.0) / 100.0;
    }

    double modulus()
    {
        return round(sqrt(re * re + im * im) * 100.0) / 100.0;
    }

    int re;
    int im;
};

int main()
{
    Complex c1 = Complex(1, 0);
    Complex c2 = Complex(0, 0);
    std::cin >> c2;

    std::cout << c1 + c2 << std::endl;
}