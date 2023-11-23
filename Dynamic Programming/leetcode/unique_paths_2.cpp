#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/unique-paths-ii/description/

class Solution
{
public:
#define ll long long int
    vector<vector<ll>> dp;
    int f(vector<vector<int>> &grid, int i, int j)
    {
        int n = grid.size();
        int m = grid[0].size();
        if (i == n - 1 and j == m - 1)
            return 1;
        if (i == n or j == m or grid[i][j] == 1)
            return dp[i][j] = 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = f(grid, i + 1, j) + f(grid, i, j + 1);
    }
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 or obstacleGrid[n - 1][m - 1] == 1)
            return 0;
        // dp.resize(101, vector<ll>(101, -1));
        // return f(obstacleGrid, 0, 0);
        dp.resize(101, vector<ll>(101, 0));
        dp[n - 1][m - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (obstacleGrid[i][m - 1] != 1)
                dp[i][m - 1] += dp[i + 1][m - 1];
        }
        for (int i = m - 2; i >= 0; i--)
        {
            if (obstacleGrid[n - 1][i] != 1)
                dp[n - 1][i] += dp[n - 1][i + 1];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = m - 2; j >= 0; j--)
            {
                if (obstacleGrid[i][j] == 1)
                    continue;
                dp[i][j] += dp[i + 1][j];
                dp[i][j] += dp[i][j + 1];
            }
        }
        return dp[0][0];
    }
};

int main()
{

    return 0;
}