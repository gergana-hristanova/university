#include <iostream>

//--- Ex 2.1 ---

bool isLeapYear(int year) {
    if (year % 4 == 0 && year % 100 != 0)
    {
        if (year % 400 == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool isValidDate(int day, int month, int year) {
    //I'm not using the format since I don't know how to enforce it (sorry).

    bool dayIsValid = (day > 0) && ((day <= 31 && month % 2 != 0) || (day <= 30 && month % 2 == 0) || (day < 28 && month == 2 && !isLeapYear(year)) || (day < 29 && month == 2 && isLeapYear(year)));
    bool monthIsValid = month > 0 && month <= 12;
    bool yearIsValid = year >= 1582; //start of the Gregorian Calendar

    return dayIsValid && monthIsValid && yearIsValid;
}

int main()
{
    std::cout << isValidDate(2, 12, 2002);
}