#include <iostream>
#include <cstring>

class String
{
    public:
    String(const char* text) : size(strlen(text)), str(new char[size + 1]{})
    {
        strcpy(str, text);
    }

    String(const String& other) : size(other.size), str(new char[other.size + 1]{})
    {
        strcpy(str, other.str);
    }

    String() : size(0), str(new char[1]{}) {}

    String& operator=(const String& other)
    {
        String copy(other);
        swap(copy);

        return *this;
    }

    ~String()
    {
        delete [] str;
    }

    bool empty() const
    {
        return size == 0;
    }

    void copy(String& dest, std::size_t copy_length) const
    {
        copy_length = (copy_length > size) ? size : copy_length;

        if (dest.size < copy_length)
        {
            delete [] dest.str;
            dest.str = new char[copy_length + 1]{};
            dest.size = copy_length;
        }

        for (std::size_t i = 0; i < copy_length; ++i)
        {
            dest.str[i] = str[i];
        }
    }

    String substr(std::size_t start_pos, std::size_t substr_length) const
    {
        char* substr = new char[substr_length + 1]{};

        for (std::size_t i = 0; i < substr_length && str[start_pos + i]; ++i)
        {
            substr[i] = str[start_pos + i];
        }

        String res = String(substr);
        delete [] substr;
        return res;
    }

    char operator[](std::size_t pos) const
    {
        return str[pos];
    }

    char& operator[](std::size_t pos)
    {
        return str[pos];
    }

    String& operator+=(const String& other)
    {
        char* new_str = new char[size + other.size + 1]{};

        for (std::size_t i = 0; i < size; ++i)
        {
            new_str[i] = str[i];
        }

        for (std::size_t i = 0; i < other.size; ++i)
        {
            new_str[size + i] = other.str[i];
        }

        delete [] str;
        str = new_str;

        size = strlen(str);

        return *this;
    }

    String operator+(const String& other) const
    {
        char* new_str = new char[size + other.size + 1]{};

        for (std::size_t i = 0; i < size; ++i)
        {
            new_str[i] = str[i];
        }

        for (std::size_t i = 0; i < other.size; ++i)
        {
            new_str[size + i] = other.str[i];
        }

        String res = String(new_str);
        delete [] new_str;
        return res;
    }

    friend std::ostream& operator<<(std::ostream& os, const String& output)
    {
        return os << output.str;
    }

    private:
    void swap(String& other)
    {
        std::swap(str, other.str);
        std::swap(size, other.size);
    }

    std::size_t size;
    char* str;
};

int main()
{
    String s1 = "brb";
    String s2 = "hello";
    s2.copy(s1, 1);

    std::cout << s1 << std::endl;
}