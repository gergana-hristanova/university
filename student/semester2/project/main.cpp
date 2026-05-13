#include <iostream>

#include "JSONNumber.cpp"
#include "JSONNull.cpp"
#include "JSONString.cpp"
#include "JSONArray.cpp"

int main()
{
    // JSONNumber n1 = JSONNumber(5.0e2);
    // std::cout << n1 << std::endl;

    // JSONNull nul = JSONNull();
    // std::cout << nul << std::endl;

    // JSONString s = JSONString("hello world");
    // std::cout << s << std::endl;

    JSONArray<int> ar = JSONArray<int>();
    ar.pushBack(new JSONNumber(1));
    std::cout << ar;
}