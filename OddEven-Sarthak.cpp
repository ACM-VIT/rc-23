#include <iostream>
using namespace std;

int solve(int n)
{
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i += 2) {
        cout << arr[i] << " ";
    }
    for (int i = n - 2; i >= 0; i -= 2) {
        cout << arr[i] << " ";
    }
    cout<<"\n";
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
            if (!std::cin || n < 1 || n > 10)
                throw -2;
            solve(n);
        }
    }
    catch (...)
    {
        std::cout << "Invalid input. Please check the question description.\n";
    }
    return 0;
}
