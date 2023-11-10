#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/detect-cycles-in-2d-grid/

class Solution
{
public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool check(int i, int j, vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        if (i < 0 or j < 0 or i >= n or j >= m)
            return false;
        return true;
    }
    bool dfs(vector<vector<bool>> &visited, vector<vector<char>> &grid, int i, int j, int par_x, int par_y)
    {
        int n = grid.size();
        int m = grid[0].size();
        visited[i][j] = 1;
        for (int d = 0; d < 4; d++)
        {
            int new_r = i + dir[d][0];
            int new_c = j + dir[d][1];
            if (check(new_r, new_c, grid) and !(new_r == par_x and new_c == par_y) and grid[new_r][new_c] == grid[i][j])
            {
                if (visited[new_r][new_c] or dfs(visited, grid, new_r, new_c, i, j))
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((not visited[i][j]) and dfs(visited, grid, i, j, -1, -1))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{

    return 0;
}