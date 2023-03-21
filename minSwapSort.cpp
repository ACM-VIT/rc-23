/*
    Author: Sai Sreekar
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void minSwaps(int n, std::vector<int> &nums)
{
    std::vector<bool> isVisited(n, false);
    std::vector<pair<int, int>> vec(n);

    for (int i = 0; i < n; i++)
    {
        vec[i].first = nums[i];
        vec[i].second = i;
    }

    sort(vec.begin(), vec.end());
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (isVisited[i] or vec[i].second == i)
        {
            continue;
        }

        int cycleSize = 0; // require cycle-1 swaps
        int j = i;

        while (!isVisited[j])
        {
            isVisited[j] = true;
            j = vec[j].second;
            cycleSize++;
        }

        if (cycleSize > 1) // if cycle
        {
            ans += cycleSize - 1;
        }
        else
        {
            ans = 0;
        }
    }

    cout << ans << "\n";
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
                if (!std::cin || vec[i] < 0 || vec[i] > 10000)
                {
                    throw -2;
                }
            }
            minSwaps(n, vec);
        }
    }
    catch (...)
    {
        std::cout << "Invalid input. Please check the question description.\n";
    }
    return 0;
}
