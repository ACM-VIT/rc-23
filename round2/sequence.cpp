/*
    Author: Sai Sreekar
*/

#include <iostream>

int main()
{
    try
    {
        int testCases;
        std::cin >> testCases;
        if (!std::cin || testCases < 1 || testCases > 150)
        {
            throw -1;
        }
        while (testCases--)
        {
            int n;
            std::cin >> n;
            if (!std::cin || n < 1 || n > 100)
            {
                throw -2;
            }
            n--;
            for (int i = 1; i <= n; i++)
            {
                n -= i;
            }
            std::cout << n + 1 << "\n";
        }
    }
    catch (...)
    {
        std::cout << "Invalid input. Please check the question description.\n";
    }
    return 0;
}
