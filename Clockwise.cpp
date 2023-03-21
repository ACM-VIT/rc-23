#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> spiralOrder(vector<vector<int> > &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    vector<int> ans;

    if (m == 0)
        return ans;

    vector<vector<bool> > seen(m, vector<bool>(n, false));
    int dr[] = {0, 1, 0, -1};
    int dc[] = {1, 0, -1, 0};

    int x = 0, y = 0, di = 0;

    for (int i = 0; i < m * n; i++)
    {
        ans.push_back(matrix[x][y]);
        seen[x][y] = true;
        int newX = x + dr[di];
        int newY = y + dc[di];

        if (0 <= newX && newX < m && 0 <= newY && newY < n && !seen[newX][newY])
        {
            x = newX;
            y = newY;
        }
        else
        {
            di = (di + 1) % 4;
            x += dr[di];
            y += dc[di];
        }
    }
    return ans;
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
            int m, n;
            std::cin >> m;
            std::cin >> n;
            if (!std::cin || m < 0 || m > 10 || n < 0 || n > 10)
                throw -2;

            vector<vector<int> > a(m, vector<int>(n));

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cin >> a[i][j];
                }
            }
            for (int x : spiralOrder(a))
            {
                cout << x << " ";
            }
        }
    }
    catch (...)
    {
        std::cout << "Invalid input. Please check the question description.\n";
    }
    return 0;
}
