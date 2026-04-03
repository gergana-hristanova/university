#include <iostream>

template <typename T>
class Vector
{
public:
    Vector() : size(0), capacity(1), vec(new T[1]) {}

    Vector(std::size_t capacity) : size(0), capacity(capacity), vec(new T[capacity]) {}

    Vector(const Vector& other) : size(other.size), capacity(other.capacity), vec(new T[other.capacity])
    {
        for (std::size_t i = 0; i < other.size; ++i)
        {
            vec[i] = other.vec[i];
        }
    }

    Vector& operator=(const Vector& other)
    {
        Vector copy(other);
        vector_swap(copy);

        return *this;
    }

    T operator[](std::size_t pos) const
    {
        if (0 <= pos && pos < size)
        {
            return vec[pos];
        }
        else
        {
            return T(0); // for lack of ability to throw exception
        }
    }

    T& operator[](std::size_t pos)
    {
        return vec[pos];
    }

    ~Vector()
    {
        delete [] vec;
    }

    void grow()
    {
        capacity *= 2;

        T* new_vec = new T[capacity];
        for (std::size_t i = 0; i < size; ++i)
        {
            new_vec[i] = vec[i];
        }

        delete [] vec;
        vec = new_vec;
    }

    Vector& push_back(T el)
    {
        if (size == capacity)
        {
            grow();
        }

        vec[size++] = el;

        return *this;
    }

    Vector& pop_back()
    {
        --size;
        
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector& v)
    {
        for (std::size_t i = 0; i < v.size; ++i)
        {
            os << v.vec[i] << " ";
        }

        return os << std::endl;
    }

private:
    std::size_t size, capacity;
    T* vec;

    void vector_swap(Vector& other)
    {
        std::swap(size, other.size);
        std::swap(capacity, other.capacity);
        std::swap(vec, other.vec);
    }
};

int main()
{
    Vector v1 = Vector<int>();
    v1.push_back(1).push_back(3).push_back(5).push_back(8).push_back(0).pop_back().push_back(9);
    std::cout << v1;
    std::cout << v1[2] << std::endl;
    v1[2] = 7;
    std::cout << v1[2];
}