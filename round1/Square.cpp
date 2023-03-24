#include <iostream>
using namespace std;

int solve(int length,int width)
{

    int total_squares = 0;
    for (int i = 1; i <= min(length, width); i++)
    {
        int squares_in_row = (length - i + 1) * (width - i + 1);
        total_squares += squares_in_row;
    }

    return total_squares;
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
            long long a, b;
            std::cin >> a >> b;
            if (!std::cin || a < 1 || a > 25 || b < 1 || b > 25)
                throw -2;
            cout<<solve(a, b);
        }
    }
    catch (...)
    {
        std::cout << "Invalid input. Please check the question description.\n";
    }
    return 0;
}