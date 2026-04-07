#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "lib/doctest/doctest/doctest.h"
#include <iostream>

template <typename T>
class Set
{
public:
    Set()
     : elems(new T[1]{T(0)}),
       size(0),
       capacity(1)
    {}

    Set(const T* arr, std::size_t size)
     : elems(new T(size)),
       size(size),
       capacity(size)
    {
        for (std::size_t i = 0; i < size; ++i)
        {
            elems[i] = arr[i];
        }
    }

    Set(T* arr, std::size_t size, std::size_t capacity)
     : elems(new T(size)),
       size(size),
       capacity(capacity)
    {
        for (std::size_t i = 0; i < size; ++i)
        {
            elems[i] = arr[i];
        }
    }

    Set(const Set &other)
     : elems(new T(other.size)),
       size(other.size),
       capacity(other.capacity)
    {
        for (std::size_t i = 0; i < other.size; ++i)
        {
            elems[i] = other.elems[i];
        }
    }

    Set& operator=(const Set &other)
    {
        Set copy(other);
        swap(other);

        return *this;
    }

    Set operator+(const Set &other) const
    {
        std::size_t res_capacity = capacity + other.capacity;
        
        T* res_elems = new T[res_capacity];
        
        for (std::size_t i = 0; i < size; ++i)
        {
            res_elems[i] = elems[i];
        }
        
        std::size_t countOtherElems = 0;
        for (std::size_t i = 0; i < other.size; ++i)
        {
            T current = other.elems[i];
            if (!hasElement(current))
            {
                res_elems[size + countOtherElems++] = current;
            }
        }
        
        return Set(res_elems, size + countOtherElems, res_capacity);
    }

    Set& operator+=(const Set &other)
    {
        std::size_t res_capacity = capacity + other.capacity;
        
        T* res_elems = new T[res_capacity];
        
        for (std::size_t i = 0; i < size; ++i)
        {
            res_elems[i] = elems[i];
        }
        
        std::size_t countOtherElems = 0;
        for (std::size_t i = 0; i < other.size; ++i)
        {
            T current = other.elems[i];
            if (!hasElement(current))
            {
                res_elems[size + countOtherElems++] = current;
            }
        }

        delete [] elems;
        
        elems = res_elems;
        size += countOtherElems;
        capacity = res_capacity;

        return *this;
    }

    T operator[](std::size_t index) const
    {
        return elems[index];
    }

    friend std::ostream& operator<<(std::ostream &os, const Set &s)
    {
        for (std::size_t i = 0; i < s.size; ++i)
        {
            os << s.elems[i] << " ";
        }

        return os << std::endl;
    }

    ~Set()
    {
        delete [] elems;
    }

    std::size_t getSize() const
    {
        return size;
    }

    std::size_t getCapacity() const
    {
        return capacity;
    }

    bool hasElement(T el) const
    {
        for (std::size_t i = 0; i < size; ++i)
        {
            if (elems[i] == el) //assuming T has an == operator
            {
                return true;
            }
        }

        return false;
    }

    Set& add(T el)
    {
        if (!hasElement(el))
        {
            if (size == capacity)
            {
                grow();
            }

            elems[size++] = el;
        }

        return *this;
    }

    Set& remove(T el)
    {
        if (hasElement(el))
        {
            T* new_elems = new T[capacity];

            for (std::size_t i = 0, j = 0; i < size; ++i)
            {
                if (elems[i] == el) //assuming T has a == operator
                {
                    ++i;
                }

                new_elems[j++] = elems[i];
            }

            delete [] elems;

            elems = new_elems;
            --size;
        }

        return *this;
    }

private:
    T* elems;
    std::size_t size, capacity;

    void swap(Set &other)
    {
        std::swap(elems, other.elems);
        std::swap(size, other.size);
        std::swap(capacity, other.capacity);
    }

    void grow()
    {
        capacity *= 2;
        T* new_elems = new T[capacity];

        for (std::size_t i = 0; i < size; ++i)
        {
            new_elems[i] = elems[i];
        }

        delete [] elems;

        elems = new_elems;
    }
};

TEST_CASE("declaration of set")
{
    SUBCASE("delcaration of empty set")
    {
        Set<int> s = Set<int>();

        CHECK_EQ(s[0], 0);
        CHECK_EQ(s.getSize(), (std::size_t) 0);
        CHECK_EQ(s.getCapacity(), (std::size_t) 1);
    }

    SUBCASE("declaration of set with const array and size")
    {
        std::size_t size = 3;
        int arr[size] = { 1, 2, 3 };

        Set<int> s = Set<int>(arr, size);

        CHECK_EQ(s.getSize(), size);
        CHECK_EQ(s.getCapacity(), size);

        for (std::size_t i = 0; i < size; ++i)
        {
            CHECK_EQ(s[i], arr[i]);
        }
    }

    SUBCASE("declaration of set with const array, size, and capacity")
    {
        std::size_t size = 3;
        std::size_t capacity = 6;
        int arr[size] = { 1, 2, 3 };

        Set<int> s = Set<int>(arr, size, capacity);

        CHECK_EQ(s.getSize(), size);
        CHECK_EQ(s.getCapacity(), capacity);

        for (std::size_t i = 0; i < size; ++i)
        {
            CHECK_EQ(s[i], arr[i]);
        }
    }

    SUBCASE("declaration of set by copying other set")
    {
        std::size_t size = 3;
        std::size_t capacity = 6;
        int arr[size] = { 1, 2, 3 };

        Set<int> s1 = Set<int>(arr, size, capacity);
        Set<int> s2 = Set<int>(s1);

        CHECK_EQ(s1.getSize(), size);
        CHECK_EQ(s1.getCapacity(), capacity);

        for (std::size_t i = 0; i < size; ++i)
        {
            CHECK_EQ(s1[i], arr[i]);
        }
    }
}

TEST_CASE("set operators")
{
    SUBCASE("set operator=")
    {
        std::size_t size = 3;
        std::size_t capacity = 6;
        int arr[size] = { 1, 2, 3 };

        Set<int> s1 = Set<int>(arr, size, capacity);
        Set<int> s2 = s1;

        CHECK_EQ(s1.getSize(), size);
        CHECK_EQ(s1.getCapacity(), capacity);

        for (std::size_t i = 0; i < size; ++i)
        {
            CHECK_EQ(s1[i], arr[i]);
        }
    }
}