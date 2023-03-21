#include <iostream>
#include <climits>
using namespace std;

int minJumps(int arr[], int n)
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
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    if (n < 1) {
        cerr << "Error: Number of elements in the array should be greater than or equal to 1." << endl;
        return 1;
    }

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int min_jumps = minJumps(arr, n);
    cout <<  min_jumps << endl;

    return 0;
}
