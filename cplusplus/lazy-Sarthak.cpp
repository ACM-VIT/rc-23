#include <iostream>
#include <cmath>

int solve(int n)
{
	int pieces = (pow(n, 2) + n + 2) / 2;
    std::cout<< pieces << std::endl;
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
            long long n;
            std::cin >> n;
            if (!std::cin || n < 1 || n > 100000)
                throw -2;
            solve(n);
        }
    }
    catch (...)
    {
        std::cout << "Invalid input. Please check the question description.\n";
    }
    return 0;
}
