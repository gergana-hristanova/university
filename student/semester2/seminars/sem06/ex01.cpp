#include <iostream>
#include <cstring>

template <typename T>
class Relation
{
public:
    Relation(T subject, T object, const char* description)
    : subject(subject),
      object(object),
      description(new char[strlen(description + 1)]{})
    {
        strcpy(this->description, description);
    }

    Relation(const Relation& other)
    : subject(other.subject),
      object(other.object),
      description(new char[strlen(other.description + 1)]{})
    {
        strcpy(this->description, other.description);
    }

    Relation& operator=(const Relation& other)
    {
        Relation copy(other);
        swap(copy);

        return *this;
    }

    ~Relation()
    {
        delete [] description;
    }

    friend std::ostream& operator<<(std::ostream& os, const Relation& r)
    {
        return os << r.subject << ' ' << r.description << ' ' << r.object << std::endl;
    }

    Relation operator*(const Relation& other)
    {
        if (object != other.subject) // assuming T has a != operator
        {
            return Relation(T(0), T(0), "");
        }

        std::size_t this_desc_len = strlen(description);
        std::size_t other_desc_len = strlen(other.description);

        char* comp_description = new char[this_desc_len + other_desc_len + 4]{};

        for (std::size_t i = 0; i < this_desc_len; ++i)
        {
            comp_description[i] = description[i];
        }

        comp_description[this_desc_len] = ' ';
        for (std::size_t i = 0; i < strlen(object); ++i)
        {
            comp_description[i] = ((char*)object)[i];
        }
        comp_description[this_desc_len + strlen(object)] = ' ';

        for (std::size_t i = 0; i < other_desc_len; ++i)
        {
            comp_description[this_desc_len + strlen(object) + i] = description[i];
        }

        return Relation(object, other.subject, comp_description);
    }

private:
    T subject;
    T object;
    char* description;

    void swap(Relation& other)
    {
        std::swap(object, other.object);
        std::swap(subject, other.subject);
        std::swap(description, other.description);
    }
};

int main()
{
    Relation<int> r1(2, 6, "is smaller than"), r2(6, 3, "is divisible by");
    std::cout << r1; //2 is smaller than 6
    std::cout << r1 * r2; //2 is smaller than 6, which is divisible by 3
}