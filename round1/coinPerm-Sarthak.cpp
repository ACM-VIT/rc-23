#include <iostream>
#include <unordered_map>
using namespace std;

int solve(int n, int *coins, int *numCoins, int sumInRupees)
{
    unordered_map<int, int> coinMap;

    for (int i = 0; i < n; i++)
    {
        coinMap[coins[i]] = numCoins[i];
    }

    int sumInPaise = sumInRupees * 100;

    for (int i = n - 1; i >= 0; i--)
    {
        int coin = coins[i];
        int num = coinMap[coin];
        while (num > 0 && sumInPaise >= coin)
        {
            sumInPaise -= coin;
            num--;
        }
    }

    if (sumInPaise == 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
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

            int coins[n], numCoins[n];
            for (int i = 0; i < n; i++)
            {
                cin >> coins[i];
            }

            for (int i = 0; i < n; i++)
            {
                cin >> numCoins[i];
            }
            int sumInRupees;
            cin >> sumInRupees;
            if (!std::cin || sumInRupees < 1 || sumInRupees > 100000)
                throw -2;

            solve(n,coins,numCoins,sumInRupees);
        }
    }
    catch(...){
        cout<< "Invalid input. Please check the question description.\n";
    }
    return 0;
}