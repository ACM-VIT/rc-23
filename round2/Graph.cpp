/*
    Author: Sai Sreekar
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

std::vector<std::pair<int, std::pair<int, int> > > adj;
int maxi = INT_MIN;
void dfs(int u, int i, int f)
{
    if (u >= adj.size() || u < 0)
    {
        return;
    }

    if (adj[u].second.second != -1 && adj[u].second.first != f)
    {
        return;
    }

    if (adj[u].second.second != -1 && adj[u].second.first == f)
    {
        maxi = std::max(maxi, i - adj[u].second.second);
        return;
    }

    adj[u].second.first = f;
    adj[u].second.second = i;

    if (adj[u].first == -1)
    {
        return;
    }

    dfs(adj[u].first, i + 1, f);
    return;
}

int longestCycle(std::vector<int> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        adj.push_back(std::make_pair(edges[i], std::make_pair(-1, -1)));
        // adj.push_back( {edges[i], {-1, -1} } );
    }

    for (int i = 0; i < edges.size(); i++)
    {
        if (adj[i].second.second == -1)
        {
            dfs(i, 0, i);
        }
    }

    if (maxi == INT_MIN)
    {
        return -1;
    }
    return maxi;
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
                if (!std::cin || vec[i] < -1 || vec[i] > n - 1 || vec[i] == i)
                {
                    throw -2;
                }
            }
            std::cout << longestCycle(vec) << '\n';
        }
    }
    catch (...)
    {
        std::cout << "Invalid input. Please check the question description.\n";
    }
}
