#include <iostream>
#include "../pract05/ex02.cpp"

template <typename U, typename V>
struct Pair
{
    U u;
    V v;
};

template <typename U, typename V>
class Function
{
public:
    Function()
     : pairs(new Pair<U, V>[1]),
       size(0),
       capacity(1) {}

    Function(const Function& other)
     : pairs(new Pair<U, V>[other.size]),
       size(other.size),
       capacity(other.capacity)
    {
        for (std::size_t i = 0; i < other.size; ++i)
        {
            pairs[i] = other.pairs[i];
        }
    }

    Function& operator=(const Function& other)
    {
        Function copy(other);
        swap(other);

        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Function& f)
    {
        os << '{';

        for (std::size_t i = 0; i < f.size; ++i)
        {
            os << f.pairs[i].u << ": " << f.pairs[i].v;
            if (i != f.size - 1)
            {
                os << ", ";
            }
        }

        return os << '}' << std::endl;
    }

    ~Function()
    {
        delete [] pairs;
    }

    Function& addPair(const U& u, const V& v)
    {
        for (std::size_t i = 0; i < size; ++i)
        {
            if (pairs[i].u == u)
            {
                pairs[i].v = v;
                return *this;
            }
        }

        if (size == capacity)
        {
            doubleCapacity();
        }

        pairs[size++] = Pair<U, V>{u, v};

        return *this;
    }

    V operator[](const U& u) const
    {
        if (hasKey(u))
        {
            for (std::size_t i = 0; i < size; ++i)
            {
                if (pairs[i].u == u)
                {
                    return pairs[i].v;
                }
            }
        }
        
        return V(0); //for lack of ability to throw exception
    }

    Maybe<V> operator()(const U& u) const
    {
        return getValue(u);
    }

    Function<U, V> operator+(const Function& other)
    {
        Pair<U, V>* new_func_pairs = new Pair<U, V>[capacity + other.capacity];

        for (std::size_t i = 0; i < size; ++i)
        {
            new_func_pairs[i] = pairs[i];
        }

        for (std::size_t i = 0; i < other.size; ++i)
        {
            new_func_pairs[size + i] = other.pairs[i];
        }

        Function<U, V> res = Function();
        res.pairs = new_func_pairs;
        res.size = size + other.size;
        res.capacity = capacity + other.capacity;

        return res;
    }

    Function<U, V>& operator+=(const Function& other)
    {
        Pair<U, V>* new_pairs = new Pair<U, V>[capacity + other.capacity];

        for (std::size_t i = 0; i < size; ++i)
        {
            new_pairs[i] = pairs[i];
        }

        for (std::size_t i = 0; i < other.size; ++i)
        {
            new_pairs[size + i] = other.pairs[i];
        }

        delete [] pairs;

        pairs = new_pairs;
        size += other.size;
        capacity += other.capacity;

        return *this;
    }

    template <typename W>
    Function<U, W> operator*(const Function<V, W> other)
    {
        Function<U, W> res = Function();

        Pair<U, W>* res_pairs = new Pair<U, W>[capacity];
        std::size_t res_size = 0;
        for (std::size_t i = 0; i < size; ++i)
        {
            for (std::size_t j = 0; j < other.size; ++j)
            {
                if (pairs[i].v == other.pairs[j].u)
                {
                    res_pairs[res_size++] = Pair<U, W>{ pairs[i].u, other.pairs[j].v};
                }
            }
        }

        res.pairs = res_pairs;
        res.size = res_size;
        res.capacity = capacity;

        return res;
    }

    Maybe<V> getValue(const U& u)
    {
        for (std::size_t i = 0; i < size; ++i)
        {
            if (pairs[i].u == u)
            {
                return Maybe<V>(pairs[i].v);
            }
        }

        return Maybe<V>();
    }

    Maybe<V> getValue(const U& u) const
    {
        for (std::size_t i = 0; i < size; ++i)
        {
            if (pairs[i].u == u)
            {
                return Maybe<V>(pairs[i].v);
            }
        }

        return Maybe<V>();
    }

    bool hasKey(const U& u) const
    {
        return (bool) getValue(u);
    }

private:
    Pair<U, V>* pairs;
    std::size_t size, capacity;

    void swap(Function& other)
    {
        std::swap(pairs, other.pairs);
        std::swap(size, other.size);
        std::swap(capacity, other.capacity);
    }

    void doubleCapacity()
    {
        capacity *= 2;

        Pair<U, V>* new_pairs = new Pair<U, V>[capacity];
        for (std::size_t i = 0; i < size; ++i)
        {
            new_pairs[i] = pairs[i];
        }

        delete [] pairs;
        pairs = new_pairs;
    }
};

int main()
{
    Function<int, int> f = Function<int, int>();

    f.addPair(1, 3).addPair(2, 4).addPair(3, 5).addPair(4, 6).addPair(1, 15);
    
    //std::cout << f;

    // std::cout << f.getValue(1);
    // std::cout << f(1);

    // std::cout << std::boolalpha << f.hasKey(1) << std::endl;
    // std::cout << std::boolalpha << f.hasKey(15) << std::endl;

    // std::cout << f[3] << std::endl;
    // std::cout << f[15] << std::endl;

    Function<int, int> g = Function<int, int>();
    g.addPair(5, 1000).addPair(4, 400);

    // std::cout << f + g;
    // f += g;
    // std::cout << f;

    std::cout << f * g;
}