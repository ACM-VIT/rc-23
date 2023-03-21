/*
    Author: Sai Sreekar
*/

#include <iostream>
#include <vector>

int getMinPartitions(std::string str)
{
    std::vector<int> partitions(str.length());
    std::vector<std::vector<bool>> dp(str.length(), std::vector<bool>(str.length(), false));

    for (int i = 0; i < str.length(); i++)
    {
        int minPartitions = i;
        for (int j = 0; j <= i; j++)
        {
            if (str[i] == str[j] && (i - j < 2 || dp[j + 1][i - 1]))
            {
                dp[j][i] = true;
                if (j == 0)
                {
                    minPartitions = std::min(minPartitions, 0);
                }
                else
                {
                    minPartitions = std::min(minPartitions, partitions[j - 1] + 1);
                }
            }
        }
        partitions[i] = minPartitions;
    }
    return partitions[str.length() - 1];
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
            if (!std::cin || n < 1 || n > 100)
            {
                throw -2;
            }

            std::string str;
            std::cin >> str;
            if (str.length() > n)
            {
                throw -2;
            }
            std::cout << getMinPartitions(str) << "\n";
        }
    }
    catch (...)
    {
        std::cout << "Invalid input. Please check the question description.\n";
    }
    return 0;
}
