#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int n) {
    for (int i = 2; i * i <= n + 1; i++)
        if (n % i == 0)
            return false;
    return true;
}

void solve(int n) {
    int ans = 0;
    for (int i = 2; i <= n; i++)
        if (n % i == 0 && isPrime(i))
            ans++;
    cout << ans << "\n";
}

int main() {
    try {
        int testcases;
        cin >> testcases;
        if (!cin || testcases < 1 || testcases > 50)
            throw -1;
        int n;
        for (int T = 0; T < testcases; T++) {
            cin >> n;
            if (!cin || n < 1 || n > round(pow(10, 7)))
                throw -2;
            solve(n);
        }
    } catch (...) { cout << "Invalid Input. Please Check the Question Description.\n"; }
    return 0;
}
