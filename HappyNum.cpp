#include <iostream>
#include <unordered_set>
using namespace std;

bool isHappy(int n)
{
    std::unordered_set<int> seen;
    while (n != 1 && !seen.count(n))
    {
        seen.insert(n);
        int sum = 0;
        while (n)
        {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        n = sum;
    }
    return n == 1;
}

int nthHappyNumber(int n)
{
    int count = -1, number = 0;
    while (count < n)
    {
        if (isHappy(number))
        {
            ++count;
        }
        ++number;
    }
    return number - 1;
}

int main(){
    try
    {
        int test;
        std::cin >> test;
        if (!std::cin || test < 1 || test > 150)
            throw -1;
        for (int t = 0; t < test; t++)
        {
            long a;
            std::cin >> a;
            if (!std::cin || a < 1 || a > 10000)
                throw -2;
            cout << nthHappyNumber(a);
        }
    }
    catch (...)
    {
        std::cout << "Invalid input. Please check the question description.\n";
    }
    return 0;
}