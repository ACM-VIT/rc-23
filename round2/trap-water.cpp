/*
    Author: DF
    Question: Trapping Rain Water
*/

// clang-format off
#include <iostream>
#include <vector>
using namespace std;
#define el '\n'
// clang-format on

void solveMyProblem(vector<long long> &arr, long long n) {
    long long sze = n - 1, prev = arr[0], prevIdx = 0, ans = 0, temp = 0;
    for (int i = 1; i <= sze; i++) {
        if (arr[i] >= prev)
            prev = arr[i], prevIdx = i, temp = 0;
        else
            ans += prev - arr[i], temp += prev - arr[i];
    }
    if (prevIdx < sze) {
        ans -= temp, prev = arr[sze];
        for (int i = sze; i >= prevIdx; i--) {
            if (arr[i] < prev)
                ans += prev - arr[i];
            else
                prev = arr[i];
        }
    }
    cout << ans << el;
}

int main() {
    try {
        long long n;
        cin >> n;
        if (!cin || (n < 0 || n > 100000))
            throw -1;
        vector<long long> arr(n);
        for (long long i = 0; i < n; i++) {
            cin >> arr[i];
            if ((!cin && i <= n - 1) || (arr[i] < 0 || arr[i] > 1000000000))
                throw -1;
        }
        solveMyProblem(arr, n);
    } catch (...) { cout << "Invalid Input. Please Check The Question Description." << endl; }
    return 0;
}
