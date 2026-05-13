#include "JSONValue.hpp"

class JSONString : public JSONValue<std::string>
{
public:
    JSONString(std::string text) : JSONValue(text) {}

    JSONType getType() const override
    {
        return JSONType::String;
    }

    friend std::ostream& operator<<(std::ostream& os, const JSONString& v)
    {
        return os << v.val;
    }
};