#include <iostream>
#include <cstring>

class Str
{
    public:
    Str()
    : value(nullptr), len(0)
    {}

    Str(const char* src)
    : value(new char[strlen(src) + 1]{}),
      len(strlen(src))
    {
        for (std::size_t i = 0; i < len + 1; i++)
        {
            value[i] = src[i];
        }
    }

    Str(const Str& other)
     : value(new char[other.len + 1]{}),
       len(other.len)
    {
        for (std::size_t i = 0; i < other.len + 1; ++i)
        {
            value[i] = other.value[i];
        }
    }

    // for "copy & swap" operator= implementation
    void swap(Str& other)
    {
        using std::swap;
        swap(value, other.value);
        swap(len, other.len);
    }

    Str& operator=(const Str& other)
    {
        Str copy = other;
        swap(copy);

        return *this;
    }

    const char* c_str()
    {
        return value;
    }

    std::size_t length()
    {
        return len;
    }

    static Str cat(const Str& str1, const Str& str2)
    {
        Str res;
        res.len = str1.len + str2.len;
        res.value = new char[res.len + 1]{};
        strcpy(res.value, strcat(str1.value, str2.value));

        return res;
    }

    Str cat(const Str& other)
    {
        Str res = cat(*this, other);
        //no idea why this is needed
        res.value[res.len] = 0;

        return res;
    }

    static int cmp(const Str& str1, const Str& str2)
    {
        return strcmp(str1.value, str2.value);
    }

    int cmp(const Str& other)
    {
        return cmp(*this, other);
    }

    ~Str()
    {
        delete[] value;
    }

    private:
    char* value;
    std::size_t len; //without terminating zero
};


int main()
{
    Str str1("Hello"), str2("World");

    std::cout << str1.c_str() << " " << str2.c_str() << std::endl; // Hello World

    std::cout << Str::cat(str1, str2).c_str() << std::endl; // HelloWorld

    std::cout << Str::cmp(str1, str2) << std::endl; // <0

    str1 = str1.cat(str2);
    std::cout << str1.c_str() << std::endl; // HelloWorld

    std::cout << str1.cmp(str2) << std::endl; // <0

    return 0;
}