#pragma once

#include <iostream>
#include <string>

enum class JSONType
{
    Object,
    Array,
    String,
    Number,
    Bool,
    Null
};

template <typename T>
class JSONValue
{
public:
    JSONValue() : val() {}
    JSONValue(T val) : val(val) {}

    virtual JSONType getType() const = 0;

    // helper for operator<< in inheritors
    virtual void stringify(std::ostream& os) const
    {
        os << val;
    }

protected:
    T val;

    virtual ~JSONValue() {}
};