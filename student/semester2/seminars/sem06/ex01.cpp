#include <iostream>

template <typename T>
class Set
{
public:
    Set()
     : elems(new T[1]),
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
        
        for (std::size_t i = 0; i < size; i++)
        {
            res_elems[i] = elems[i];
        }
        
        for (std::size_t i = 0; i < other.size; i++)
        {
            res_elems[size + i] = other.elems[i];
        }
        
        return Set(res_elems, size + other.size, res_capacity);
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

int main()
{
    Set<int> s1 = Set<int>();
    s1.add(1).add(3).add(2).add(4).add(4).remove(2);
    
    int s2_elems[3] = { 1, 2, 3 };
    Set<int> s2 = Set<int>()
}