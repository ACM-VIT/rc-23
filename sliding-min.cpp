/*
    Author: DF
    Question: Sliding Min
*/

// clang-format off
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
#define el '\n'
// clang-format on

void solveMyProblem(int n, int k, vector<int> &arr) {
    deque<long long int> dq;
    for (int i = 0; i < k; i++) {
        while (!dq.empty() && arr[dq.front()] >= arr[i])
            dq.pop_front();
        dq.push_front(i);
    }
    cout << arr[dq.back()] << " ";
    for (int i = k; i < n; i++) {
        while (!dq.empty() && dq.back() <= (i - k))
            dq.pop_back();
        while (!dq.empty() && arr[dq.front()] >= arr[i])
            dq.pop_front();
        dq.push_front(i);
        cout << arr[dq.back()] << " ";
    }
    cout << el;
}

int main() {
    try {
        int n, k;
        cin >> n >> k;
        if (!cin || (n < 0 || n > 100000) || (k > n))
            throw -1;
        vector<int> arr(n);
        for (long long i = 0; i < n; i++) {
            cin >> arr[i];
            if ((!cin && i <= n - 1) || (arr[i] < 1 || arr[i] > 1000000000))
                throw -1;
        }
        solveMyProblem(n, k, arr);
    } catch (...) { cout << "Invalid Input. Please Check The Question Description." << endl; }
    return 0;
}
