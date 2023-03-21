// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> spiralOrder(vector<vector<int> >& matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    vector<int> ans;

    if (m == 0)
        return ans;

    vector<vector<bool> > seen(m, vector<bool>(n, false));
    int dr[] = { 0, 1, 0, -1 };
    int dc[] = { 1, 0, -1, 0 };

    int x = 0, y = 0, di = 0;

    // Iterate from 0 to m * n - 1
    for (int i = 0; i < m * n; i++) {
        ans.push_back(matrix[x][y]);
        seen[x][y] = true;
        int newX = x + dr[di];
        int newY = y + dc[di];

        if (0 <= newX && newX < m && 0 <= newY && newY < n
            && !seen[newX][newY]) {
            x = newX;
            y = newY;
        }
        else {
            di = (di + 1) % 4;
            x += dr[di];
            y += dc[di];
        }
    }
    return ans;
}

// Driver code
int main()
{
    int m, n;
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;

    vector<vector<int> > a(m, vector<int>(n));
    cout << "Enter the elements of the matrix row-wise:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    // Function call
    for (int x : spiralOrder(a)) {
        cout << x << " ";
    }
    return 0;
}
