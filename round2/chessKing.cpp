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
            std::string s;
            std::cin >> s;
            if (!std::cin || s.size() != 2 || s[0] < 'a' || s[0] > 'h' || s[1] < '1' || s[1] > '8')
            {
                throw -2;
            }
            if (s == "a1" || s == "a8" || s == "h1" || s == "h8")
            {
                std::cout << 3 << "\n";
            }
            else if (s[0] == 'a' || s[0] == 'h' || s[1] == '1' || s[1] == '8')
            {
                std::cout << 5 << "\n";
            }
            else
            {
                std::cout << 8 << "\n";
            }
        }
    }
    catch (...)
    {
        std::cout << "Invalid input. Please check the question description.\n";
    }

    return 0;
}
