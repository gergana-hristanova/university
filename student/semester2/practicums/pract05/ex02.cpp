#include <iostream>
#include <cassert>

template <typename T>
class Maybe
{
    public:
    Maybe() : isNull(true) {}

    Maybe(T value) : data(value), isNull(false) {}

    bool hasValue() const
    {
        return !isNull;
    }

    T get() const
    {
        assert(hasValue());
        return data;
    }

    void reset()
    {
        data = T(0);
        isNull = true;
    }

    Maybe& operator=(T value)
    {
        data = value;
        isNull = false;
        return *this;
    }

    Maybe& operator=(const Maybe<T>& other)
    {
        data = other.data;
        isNull = false;
        return *this;
    }

    operator bool()
    {
        return hasValue();
    }

    //for testing
    void print()
    {
        if (!hasValue())
        {
            std::cout << "Data is null!" << std::endl;
        }
        else
        {
            std::cout << "Data: " << data << std::endl;
        }
    }

    private:
    T data;
    bool isNull;
};

int main()
{
    Maybe<int> m1 = Maybe<int>();
    m1.print();
    m1 = 7;
    std::cout << m1.get() << std::endl;
    m1.print();

    std::cout << (bool)m1 << std::endl;
}