/*
    Author: DF
    Question: Right Angle Triangle
*/

// clang-format off
#include <iostream>
#include <vector>
using namespace std;
#define el '\n'
// clang-format on

void solveMyProblem(vector<vector<long long> > &hold) {
    for (vector<long long> arr : hold) {
        int A = ((arr[2] - arr[0]) * (arr[2] - arr[0])) + ((arr[3] - arr[1]) * (arr[3] - arr[1]));
        int B = ((arr[4] - arr[2]) * (arr[4] - arr[2])) + ((arr[5] - arr[3]) * (arr[5] - arr[3]));
        int C = ((arr[4] - arr[0]) * (arr[4] - arr[0])) + ((arr[5] - arr[1]) * (arr[5] - arr[1]));
        if ((A > 0 && B > 0 && C > 0) && (A == (B + C) || B == (A + C) || C == (A + B)))
            cout << "YES" << el;
        else
            cout << "NO" << el;
    }
}

int main() {
    try {
        long long n;
        cin >> n;
        if (!cin || (n < 0 || n > 10))
            throw -1;
        vector<vector<long long> > arr(n);
        for (long long i = 0; i < n; i++) {
            vector<long long> hold(6);
            for (int j = 0; j < 6; j++) {
                cin >> hold[j];
                if ((!cin && j <= 5) || (hold[j] < -1000000000 || hold[j] > 1000000000))
                    throw -1;
            }
            arr[i] = hold;
        }
        solveMyProblem(arr);
    } catch (...) { cout << "Invalid Input. Please Check The Question Description." << endl; }
    return 0;
}
