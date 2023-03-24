/*
    Author: DF
    Question: Modulo A % B
*/

// clang-format off
#include <iostream>
#include <vector>
using namespace std;
#define el '\n'
// clang-format on

void solveMyProblem(vector<pair<long long, long long> > &arr) {
    for (pair<long long, long long> i : arr)
        cout << i.first % i.second << el;
}

int main() {
    try {
        long long n;
        cin >> n;
        if (!cin || (n < 0 || n > 100))
            throw -1;
        vector<pair<long long, long long> > arr(n);
        for (long long i = 0; i < n; i++) {
            cin >> arr[i].first;
            if ((!cin && i <= n - 1) || (arr[i].first < 1 || arr[i].first > 1000000000))
                throw -1;
            cin >> arr[i].second;
            if ((!cin && i <= n - 1) || (arr[i].second < 1 || arr[i].second > 100000000))
                throw -1;
        }
        solveMyProblem(arr);
    } catch (...) { cout << "Invalid Input. Please Check The Question Description." << endl; }
    return 0;
}
