#include <iostream>

using namespace std;

int main() {

    // --- Ex 1 ---

    // int n;
    // cin >> n;

    // switch (n)
    // {
    //     case 1: cout << "Monday"; break;
    //     case 2: cout << "Tuesday"; break;
    //     case 3: cout << "Wednesday"; break;
    //     case 4: cout << "Thursday"; break;
    //     case 5: cout << "Friday"; break;
    //     case 6: cout << "Saturday"; break;
    //     case 7: cout << "Sunday"; break;
    //     default: cout << "No such day!"; break;
    // }

    // --- Ex 2 ---

    // int n;
    // cin >> n;

    // if (n < 100)
    // {
    //     cout << "Less than 100";
    // }
    // else if (n > 200)
    // {
    //     cout << "Greater than 200";
    // }
    // else
    // {
    //     cout << "Between 100 and 200";
    // }

    // --- Ex 3 ---

    // double speed;
    // cin >> speed;

    // if (speed < 0)
    //     cout << "Error! Speed cannot be negative!";
    // else if (speed <= 10)
    //     cout << "slow";
    // else if (speed <= 50)
    //     cout << "average";
    // else if (speed <= 150)
    //     cout << "fast";
    // else if (speed <= 1000)
    //     cout << "extremely fast";

    // --- Ex 4 ---

    // char shape;
    // cin >> shape;

    // switch (shape)
    // {
    // case 's':
    //     double side;
    //     cin >> side;
    //     cout << side * side;
    //     break;

    // case 'r':
    //     double sideA, sideB;
    //     cin >> sideA >> sideB;
    //     cout << sideA * sideB;
    //     break;
    // case 'c':
    //     double radius;
    //     cin >> radius;
    //     cout << 22.0 / 7 * radius * radius;
    //     break;
    // case 't':
    //     double base, height;
    //     cin >> base >> height;
    //     cout << base * height / 2;
    // }

    // --- Ex 5 ---

    int hours, mins;
    cin >> hours >> mins;

    hours = (mins > 15) ? (hours == 23) ? 0 : hours + 1 : hours;
    mins = (mins > 45) ? mins - 45 : mins + 15;

    if (hours < 10)
    {
        cout << '0';
    }
        
    cout << hours << ':';

    if (mins < 10)
    {
        cout << '0';
    }
        
    cout << mins;
}