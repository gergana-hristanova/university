#include <string>

#include "JSONValue.hpp"

class JSONNumber : public JSONValue<double>
{
public:
    JSONNumber(double number) : JSONValue<double>(number) {}

    JSONType getType() const override
    {
        return JSONType::Number;
    }

    friend std::ostream& operator<<(std::ostream& os, const JSONNumber& v)
    {
        return os << v.val;
    }
};