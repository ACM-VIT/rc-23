/*
    Author: Sai Sreekar
*/

#include <iostream>
#include <vector>
#define MAX 10000

std::vector<std::vector<int>> sparseTable(MAX, std::vector<int>(MAX, -1));

void buildSparseTable(std::vector<int> &vec, int n)
{
    for (int i = 0; i < n; i++)
    {
        sparseTable[i][0] = vec[i];
    }

    for (int j = 1; (1 << j) <= n; j++)
    {
        for (int i = 0; (i + (1 << j) - 1) < n; i++)
        {
            if (sparseTable[i][j - 1] <
                sparseTable[i + (1 << (j - 1))][j - 1])
            {
                sparseTable[i][j] = sparseTable[i][j - 1];
            }
            else
            {
                sparseTable[i][j] =
                    sparseTable[i + (1 << (j - 1))][j - 1];
            }
        }
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

            buildSparseTable(vec, n);

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (sparseTable[i][j] != -1)
                    {
                        std::cout << sparseTable[i][j] << " ";
                    }
                }
                std::cout << "\n";
            }
        }
    }
    catch (...)
    {
        std::cout << "Invalid input. Please check the question description.\n";
    }

    return 0;
}
