#include <iostream>
using namespace std;

int solve(int day, int month, int year)
{
    int century, decade;
    int gregorian_day;

    if (month > 2) {
        month -= 3;
    } else {
        month += 9;
        year--;
    }
    century = year / 100;
    decade = year % 100;
    gregorian_day = (146097 * century) / 4 + (1461 * decade) / 4 + (153 * month + 2) / 5 + day + 1721119 - (century * 3) / 4;

    int day_of_week = gregorian_day % 7;

    switch (day_of_week) {
        case 0:
            cout << "Sunday" << endl;
            break;
        case 1:
            cout << "Monday" << endl;
            break;
        case 2:
            cout << "Tuesday" << endl;
            break;
        case 3:
            cout << "Wednesday" << endl;
            break;
        case 4:
            cout << "Thursday" << endl;
            break;
        case 5:
            cout << "Friday" << endl;
            break;
        case 6:
            cout << "Saturday" << endl;
            break;
    }
}

int main()
{
    try
    {
        int test;
        std::cin >> test;
        if (!std::cin || test < 1 || test > 150)
            throw -1;
        for (int t = 0; t < test; t++)
        {
            long long a, b, c;
            std::cin >> a >> b >> c;
            if (!std::cin || a < 1 || a > 31 || b < 1 || b > 12 || c < 1 || c > 10000)
                throw -2;
            solve(a, b, c);
        }
    }
    catch (...)
    {
        cout<<"Invalid input. Please check the question description.\n";
    }

    return 0;
}
