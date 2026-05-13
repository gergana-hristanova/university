#include <iostream>
#include <vector>
#include <functional>

template <typename U, typename V>
class LazyMap
{
public:
    LazyMap(const std::vector<U>& source, std::function<V(U)> f)
    : source(source),
      f(f)
    {}

    class iterator
    {
        typename std::vector<U>::const_iterator it;
        const std::function<V(U)>& f;

    public:
        iterator(typename std::vector<U>::const_iterator it, const std::function<V(U)>& f)
        : it(it), f(f)
        {}

        V operator*() const
        {
            return f(*it);
        }

        bool operator!=(const iterator& other) const
        {
            return it != other.it;
        }

        bool operator==(const iterator& other) const
        {
            return it == other.it;
        }

        iterator operator++(int)
        {
            iterator old = *this;
            operator++();
            return old;
        }

        iterator& operator++()
        {
            ++it;
            return *this;
        }
    };

    iterator begin() const
    {
        return iterator(source.begin(), f);
    };

    iterator end() const
    {
        return iterator(source.end(), f);
    };

private:
    const std::vector<U>& source;
    const std::function<V(U)> f;
};

int main()
{
    std::vector<int> v = {1, 2, 3};
    auto f = [](int x) { return x * x; };

    for (int x : LazyMap<int, int>(v, f))
    {
        std::cout << x << std::endl;
    }
}