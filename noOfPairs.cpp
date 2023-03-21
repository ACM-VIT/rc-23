/*
    Author: Sai Sreekar
*/

#include <iostream>
#include <unordered_map>

void solve(int n, std::string s)
{

    std::unordered_map<char, int> ump;
    for (int i = 0; i < n; i++)
    {
        ump[s[i]]++;
    }

    int res = 0;

    for (auto it : ump)
    {
        if (it.second > 0)
        {
            if (isupper(it.first))
            {
                if (ump.find(tolower(it.first)) != ump.end())
                {
                    if (ump[it.first] > ump[tolower(it.first)])
                    {
                        res += ump[tolower(it.first)];
                        ump[it.first] -= ump[tolower(it.first)];
                        ump[tolower(it.first)] = 0;
                    }
                    else
                    {
                        res += ump[it.first];
                        ump[tolower(it.first)] -= ump[it.first];
                        ump[it.first] = 0;
                    }
                }
            }
            else
            {
                if (ump.find(toupper(it.first)) != ump.end())
                {
                    if (ump[it.first] > ump[toupper(it.first)])
                    {
                        res += ump[toupper(it.first)];
                        ump[it.first] -= ump[toupper(it.first)];
                        ump[toupper(it.first)] = 0;
                    }
                    else
                    {
                        res += ump[it.first];
                        ump[toupper(it.first)] -= ump[it.first];
                        ump[it.first] = 0;
                    }
                }
            }
        }
    }

    std::cout << res << "\n";
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
            std::string s;
            std::cin >> s;
            if (s.size() > n)
            {
                throw -2;
            }
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] >= 'a' && s[i] <= 'z')
                {
                    continue;
                }
                else if (s[i] >= 'A' && s[i] <= 'Z')
                {
                    continue;
                }
                else
                {
                    throw -2;
                }
            }
            solve(n, s);
        }
    }
    catch (...)
    {
        std::cout << "Invalid input. Please check the question description.\n";
    }

    return 0;
}
