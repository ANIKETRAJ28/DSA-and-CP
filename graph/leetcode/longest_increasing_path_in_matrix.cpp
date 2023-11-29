#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

class Solution
{
public:
    vector<vector<int>> dis = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    vector<vector<int>> dp;
    bool check(vector<vector<int>> &matrix, int i, int j)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        if (i < 0 or j < 0 or i >= n or j >= m)
            return false;
        return true;
    }
    int dfs(vector<vector<int>> &matrix, int i, int j)
    {
        int ans = 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        for (int d = 0; d < 4; d++)
        {
            int r = i + dis[d][0];
            int c = j + dis[d][1];
            if (check(matrix, r, c))
            {
                if (matrix[i][j] < matrix[r][c])
                {
                    ans = max(ans, 1 + dfs(matrix, r, c));
                }
            }
        }
        return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        dp.resize(n, vector<int>(m, -1));
        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans = max(ans, 1 + dfs(matrix, i, j));
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}