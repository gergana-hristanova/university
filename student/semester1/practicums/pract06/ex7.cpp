#include <iostream>

bool isLeapYear(int year)
{
    return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}

bool isValidDate(unsigned day, unsigned month, unsigned year)
{
    bool isValidYear = 1 <= year;
    bool isValidMonth = 1 <= month && month <= 12;

    bool isValidDay = 1 <= day;
    if (month % 2 != 0)
        isValidDay *= day <= 31;
    else if (month == 2 && isLeapYear(year))
        isValidDay *= day <= 29;
    else if (month == 2 && !isLeapYear(year))
        isValidDay *= day <= 28;
    else if (month % 2 == 0)
        isValidDay *= day <= 30;
}

int main()
{
    unsigned day, month, year;
    std::cin >> day >> month >> year;

    //validity check
    if (!isValidDate(day, month, year))
    {
        std::cout << "Error! Date is invalid!";
        return 0;
    }


}