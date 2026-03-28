#include <iostream>

using namespace std;

int main() {

    // --- Ex 1 ---

    // int n;
    // cin >> n;
    // cout << (n % 3 == 0);

    // --- Ex 2 ---

    // int n;
    // cin >> n;
    // bool result = (n % 2 == 0) ? 1 : 0;
    // cout << result;

    // --- Ex 3 ---

    // int grade;
    // cin >> grade;

    // switch (grade)
    // {
    //     case 2: cout << "Poor"; break;
    //     case 3: cout << "Bad"; break;
    //     case 4: cout << "Good"; break;
    //     case 5: cout << "Very Good"; break;
    //     case 6: cout << "Excellent"; break;
    //     default: cout << "Error! No such grade!"; break;
    // }

    // --- Ex 4 ---

    // int year;
    // cin >> year;

    // if (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))
    // {
    //     cout << "Not leap year";
    // }
    // else
    // {
    //     cout << "Leap year";
    // }

    // --- Ex 5 ---

    // int n1, n2, n3;
    // cin >> n1 >> n2 >> n3;

    // int mid = (n1 <= n2 && n2 <= n3) ? n2 : (n2 <= n3 && n3 <= n1) ? n3 : n1;
    // cout << mid;

    // --- Ex 5.5 ---

    // int n1, n2, n3;
    // cin >> n1 >> n2 >> n3;

    // int min = (n1 < n2 && n2 < n3) ? n1 : (n2 < n3 && n3 < n1) ? n2 : n3;
    // int mid = (n1 < n2 && n2 < n3) ? n2 : (n2 < n3 && n3 < n1) ? n3 : n1;
    // int max = (n1 < n2 && n2 < n3) ? n3 : (n2 < n3 && n3 < n1) ? n1 : n2;
    // cout << max * 100 + mid * 10 + min;

    // --- Ex 6 ---

    // We were told not to do it by the assistants.

    // --- Ex 7 ---

    // char symbol;
    // cin >> symbol;

    // char result = 0;
    
    // if (!('A' <= symbol && symbol <= 'z'))
    // {
    //     cout << "Error! The symbol is not a letter!";
    // }
    // else
    // {
    //     if ('A' <= symbol && symbol <= 'Z') {
    //         cout << "Uppercase";
    //         result = symbol + 32;
    //     }
    //     else if ('a' <= symbol && symbol <= 'z')
    //     {
    //         cout << "Lowercase";
    //         result = symbol - 32;
    //     }
        
    //     if (symbol == 'a' || symbol == 'e' || symbol == 'i' || symbol == 'o' || symbol == 'u' || symbol == 'A' || symbol == 'E' || symbol == 'I' || symbol == 'O' || symbol == 'U')
    //     {
    //         cout << " Vowel" << endl;
    //     }
    //     else
    //     {
    //         cout << " Consonant" << endl;
    //     }

    //     cout << result << endl;
    // }

    // --- Ex 8 ---

    // double x, y;
    // cin >> x >> y;

    // if (x == 0 || y == 0)
    // {
    //     cout << "Error! Point is not in a quadrant!";
    // }
    // else if (x > 0 && y > 0)
    // {
    //     cout << "First";
    // }
    // else if (x > 0 && y < 0)
    // {
    //     cout << "Fourth";
    // }
    // else if (x < 0 && y < 0)
    // {
    //     cout << "Third";
    // }
    // else if (x < 0 && y > 0)
    // {
    //     cout << "Second";
    // }

    // --- Ex 9 ---

    // double a, b, c;
    // cin >> a >> b >> c;
    
    // bool triangleExists = a + b > c && a + c > b && b + c > a;
    // if (!triangleExists)
    // {
    //     cout << "Error! Triangle does not exist!";
    // }
    // else
    // {
    //     if ((a * a + b * b == c * c) || (b * b + c * c == a * a) || (a * a + b * b == c * c))
    //     {
    //         cout << "Right-angled triangle";
    //     }
    //     else if (a == b && b == c)
    //     {
    //         cout << "Equilateral triangle";
    //     }
    //     else if ((a == b && b != c) || (b == c && c != a) || (a == c && c != b))
    //     {
    //         cout << "Isosceles triangle";
    //     }
    //     else
    //     {
    //         cout << "Scalene triangle";
    //     }
    // }

    // --- Ex 10 ---

    // double intervalStart, intervalEnd, num;
    // cin >> intervalStart >> intervalEnd >> num;

    // if (num < intervalStart || num > intervalEnd)
    // {
    //     cout << "The number is NOT within the given interval.";
    // }
    // else
    // {
    //     cout << "The number is within the given interval." << endl;

    // Here I've used == with double, which is usually a mistake. But here I'm sure all doubles come straight from the console, so there's no chance the values aren't what they seem.
    //     if (num == intervalStart || num == intervalEnd)
    //     {
    //         cout << "The interval is closed.";
    //     }
    //     else
    //     {
    //         cout << "The interval is open.";
    //     }
    // }

    // --- Ex 11 ---

    // int num;
    // cin >> num;

    // int newNum1 = (num / 1000) % 10 * 10 + num % 10;
    // int newNum2 = (num / 100) % 10 * 10 + (num / 10) % 10;

    // if (newNum1 < newNum2)
    // {
    //     cout << newNum1 << " < " << newNum2;
    // }
    // else if (newNum1 > newNum2)
    // {
    //     cout << newNum1 << " > " << newNum2;
    // }
    // else
    // {
    //     cout << newNum1 << " == " << newNum2;
    // }

    // --- Ex 12 ---

    // int day, month;
    // cin >> day >> month;

    // int maxDay = (month == 2) ? 28 : 31;
    // if (month < 1 || month > 12 || day < 1 || day > maxDay)
    // {
    //     cout << "Error! Invalid date!";
    // }
    // else
    // {
    //     //Maybe this is a little too extravagant, but it was good exercise.
    //     month = (day != 1) ? month : (month == 1) ? 12 : month - 1;
    //     day = (day == 1) ? (month == 2) ? 28 : 31 : day - 1;
            
    //     cout << day << " " << month;
    // }

    // --- Ex 12.5 ---

    // int day, month, year;
    // cin >> day >> month >> year;

    // bool isLeapYear = !(year % 4 != 0 || (year % 100 == 0 && year % 400 != 0));

    // int maxDay = (month == 2) ? isLeapYear ? 29 : 28 : 31;

    // if (month < 1 || month > 12 || day < 1 || day > maxDay || year < 1) //Validation
    // {
    //     cout << "Error! Invalid date!";
    // }
    // else
    // {
    //     year = (month == 1 && day == 1) ? year - 1 : year;
    //     month = (day != 1) ? month : (month == 1) ? 12 : month - 1;
    //     day = (day == 1) ? (month == 2) ? isLeapYear ? 29 : 28 : 31 : day - 1;
            
    //     cout << day << " " << month << " " << year;
    // }

    // --- Ex 13 ---

    // double n1, n2;
    // char operation;

    // cin >> n1 >> operation >> n2;

    // switch (operation)
    // {
    //     case '+': cout << (n1 + n2); break;
    //     case '-': cout << (n1 - n2); break;
    //     case '*': cout << (n1 * n2); break;
    //     case '/':
    //         if (n2 == 0)
    //         {
    //             cout << "Error! Cannot divide by zero!";
    //         }
    //         else
    //         {
    //             cout << (n1 / n2);
    //         }

    //         break;
    // }

    // --- Ex 14 ---

    // int n1, n2, n3, n4, n5;
    // cin >> n1 >> n2 >> n3 >> n4 >> n5;

    // //Since n1 and n5 have only one neighbor, they automatically fulfill the trion condition.
    // bool trionCheckN2 = (n2 >= n1 && n2 >= n3) || (n2 <= n1 && n2 <= n3);
    // bool trionCheckN3 = (n3 >= n2 && n3 >= n4) || (n3 <= n2 && n3 <= n4);
    // bool trionCheckN4 = (n4 >= n3 && n4 >= n5) || (n4 <= n3 && n4 <= n5);

    // bool isTrion = trionCheckN2 && trionCheckN3 && trionCheckN4;
    // if (isTrion)
    // {
    //     cout << "yes";
    // }
    // else
    // {
    //     cout << "no";
    // }

    // --- Ex 15 ---

    // double r;
    // int x, y;
    // cin >> r >> x >> y;

    // double pointRSq = x * x + y * y;

    // if (r * r == pointRSq)
    // {
    //     cout << "On the circle";
    // }
    // else if (r * r < pointRSq)
    // {
    //     cout << "Out of the circle";
    // }
    // else
    // {
    //     cout << "In the circle";
    // }

    // --- Ex 16 ---

    // char startA, endA, startB, endB, checkCh;
    // cin >> startA >> endA >> startB >> endB >> checkCh;

    // // Validation
    // if (!('A' <= startA && startA <= 'Z' && 'A' <= endA && endA <= 'Z'))
    // {
    //     cout << "Error! First two characters must be uppercase letters!";
    // }
    // else if (!('a' <= startB && startB <= 'z' && 'a' <= endB && endB <= 'z'))
    // {
    //     cout << "Error! Second two characters must be lowercase letters!";
    // }
    // else if (!('A' <= checkCh && checkCh <= 'z'))
    // {
    //     cout << "Error! The fifth character must be a letter!";
    // }
    // // Function
    // else
    // {
    //     bool isInA = checkCh >= startA && checkCh <= endA;
    //     bool isInB = checkCh >= startB && checkCh <= endB;

    //     if (isInA || isInB) // Union
    //     {
    //         cout << "true, ";
    //     }
    //     else
    //     {
    //         cout << "false, ";
    //     }

    //     if (isInA && isInB) // Intersection
    //     {
    //         cout << "true, ";
    //     }
    //     else
    //     {
    //         cout << "false, ";
    //     }

    //     if (isInA && !isInB) // Difference
    //     {
    //         cout << "true, ";
    //     }
    //     else
    //     {
    //         cout << "false, ";
    //     }

    //     if ((isInA && !isInB) || (!isInA && isInB)) // Xor
    //     {
    //         cout << "true";
    //     }
    //     else
    //     {
    //         cout << "false";
    //     }
    // }
}
