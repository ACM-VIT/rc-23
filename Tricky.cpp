#include <iostream>
#include <set>

int numSquareSum(int n)
{
    int squareSum = 0;
    while (n)
    {
        squareSum += (n % 10) * (n % 10);
        n /= 10;
    }
    return squareSum;
}

bool isHappyNumber(int n)
{
    std::set<int> st;
    while (1)
    {
        n = numSquareSum(n);
        if (n == 1)
        {
            return true;
        }
        if (st.find(n) != st.end())
        {
            return false;
        }
        st.insert(n);
    }
}
bool isPalindrome(int n)
{
    int reversed = 0, remainder, original;
    original = n;

    while (n != 0)
    {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }

    if (original == reversed)
    {
        return true;
    }
    return false;
}

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
            if (!std::cin || n < 1 || n > 10000)
            {
                throw -2;
            }

            std::cout << "ACM\n";
            if (isPalindrome(n))//O(n)
            {
                std::cout << "Code2Create\n";
            }
            if (isHappyNumber(n))//O(nlogn)
            {
                std::cout << "Reverse Coding\n";
            }
            if (n == 6 || n == 28 || n == 496 || n == 8128)// perfect numbers
            {
                std::cout << "Cryptic Hunt\n";
            }
        }
    }
    catch (...)
    {
        std::cout << "Invalid input. Please check the question description.\n";
    }
    return 0;
}
