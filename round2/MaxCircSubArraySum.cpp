/*
    Author: Sai Sreekar
*/

#include <iostream>
#include <vector>

int getMaxSum(std::vector<int> &nums)
{
    int currMax = 0, currMin = 0, sum = 0;
    int maxSum = nums[0], minSum = nums[0];
    
    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        currMax = std::max(currMax, 0) + num;
        maxSum = std::max(maxSum, currMax);
        currMin = std::min(currMin, 0) + num;
        minSum = std::min(minSum, currMin);
        sum += num;
    }

    if (sum == minSum)
    {
        return maxSum;
    }
    else
    {
        return std::max(maxSum, sum - minSum);
    }
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

            std::vector<int> vec(n);
            for (int i = 0; i < n; i++)
            {
                std::cin >> vec[i];
                if (!std::cin || vec[i] < -10000 || vec[i] > 10000)
                {
                    throw -2;
                }
            }

            std::cout << getMaxSum(vec) << "\n";
        }
    }
    catch (...)
    {
        std::cout << "Invalid input. Please check the question description.\n";
    }

    return 0;
}
