#include <vector>

#include "JSONValue.hpp"

template <typename T>
class JSONArray : public JSONValue<std::vector<JSONValue<T>*>>
{
public:
    JSONArray() : JSONValue<std::vector<JSONValue<T>*>>() {}

    JSONType getType() const
    {
        return JSONType::Array;
    }

    JSONArray& pushBack(T* item)
    {
        this->val.push_back(item);
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const JSONArray& v)
    {
        for (T* item : v.val)
        {
            os << item;
        }

        return os;
    }

    ~JSONArray()
    {
        for (T* item : this->val)
        {
            delete item;
        }
    }
};