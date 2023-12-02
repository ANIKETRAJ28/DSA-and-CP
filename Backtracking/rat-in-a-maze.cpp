// #include <bits/stdc++.h>
// #define ll long long int
// #define infp INT_MAX
// #define infn INT_MIN
// #define pp pair<int, int>
// #define mod 1000000007

// using namespace std;
// template <typename T>
// using vec = vector<T>;

// vec<vec<int>> maze;
// int n;

// vec<vec<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// bool check(int row, int col)
// {
//     if (row < 0 or row >= n or col < 0 or col >= n or maze[row][col] == 1)
//         return false;
//     return true;
// }

// int f(int row, int col)
// {
//     if (row == n - 1 and col == n - 1)
//     {
//         return 1;
//     }
//     int ans = 0;
//     for (int d = 0; d < 4; d++)
//     {
//         int new_r = row + dir[d][0];
//         int new_c = col + dir[d][1];
//         if (check(new_r, new_c))
//         {
//             maze[new_r][new_c] = 1;
//             ans += f(new_r, new_c);
//             maze[new_r][new_c] = 0;
//         }
//     }
//     return ans;
// }

// int main()
// {
//     cin >> n;
//     maze.resize(n, vec<int>(n));
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cin >> maze[i][j];
//         }
//     }
//     cout << f(0, 0);
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    bool check(vector<vector<int>> &grid, int row, int col, int n)
    {
        if (row < 0 or col < 0 or row <= n or col >= n or grid[row][col] != 1)
            return false;
        return true;
    }
    vector<string> final_ans;
    void f(vector<vector<int>> &grid, string ans, int row, int col)
    {
        int n = grid.size();
        if (row == n - 1 and col == n - 1)
        {
            final_ans.push_back(ans);
            return;
        }
        if (check(grid, row - 1, col, n))
        {
            grid[row - 1][col] = 0;
            f(grid, ans + 'U', row - 1, col);
            grid[row - 1][col] = 1;
        }
        if (check(grid, row + 1, col, n))
        {
            grid[row + 1][col] = 0;
            f(grid, ans + 'D', row - 1, col);
            grid[row + 1][col] = 1;
        }
        if (check(grid, row, col - 1, n))
        {
            grid[row][col - 1] = 0;
            f(grid, ans + 'L', row, col - 1);
            grid[row][col - 1] = 0;
        }
        if (check(grid, row, col + 1, n))
        {
            grid[row][col + 1] = 0;
            f(grid, ans + 'R', row, col + 1);
            grid[row][col + 1] = 1;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        f(m, "", 0, 0);
        for (int i = 0; i < final_ans.size(); i++)
        {
            cout << final_ans[i] << " ";
        }
        return final_ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
        {
            cout << -1;
        }
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}