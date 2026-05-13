#include <string>

#include "JSONValue.hpp"

class JSONNull : public JSONValue<bool>
{
public:
    JSONNull() : JSONValue() {}

    JSONType getType() const override
    {
        return JSONType::Null;
    }

    friend std::ostream& operator<<(std::ostream& os, const JSONNull& v)
    {
        // parameter v is for the sake of operator<< syntax

        return os << "null";
    }
};