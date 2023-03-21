#include <iostream>
#include <climits>
using namespace std;

int minJumps(long arr[],long n)
{
    if (n == 1)
        return 0;
    int res = INT_MAX;
    for (int i = n - 2; i >= 0; i--) {
        if (i + arr[i] >= n - 1) {
            int sub_res = minJumps(arr, i + 1);
            if (sub_res != INT_MAX)
                res = min(res, sub_res + 1);
        }
    }
    return res;
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
            long a;
            std::cin >> a;
            
            if (!std::cin || a<0 || a>25)
                throw -2;
            long arr[a];
            for (int i = 0; i < a; i++)
            {
                cin >> arr[i];
            }
            cout<<minJumps(arr, a);
        }
    }
    catch (...)
    {
        std::cout << "Invalid input. Please check the question description.\n";
    }
    return 0;
}