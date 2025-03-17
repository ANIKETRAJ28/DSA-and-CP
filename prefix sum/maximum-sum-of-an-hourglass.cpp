#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/maximum-sum-of-an-hourglass/description/

class Solution
{
public:
  int maxSum(vector<vector<int>> &grid)
  {
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < n; i++)
    {
      for (int j = 1; j < m; j++)
      {
        grid[i][j] += grid[i][j - 1];
      }
    }
    int ans = 0;
    for (int i = 0; i + 2 < n; i++)
    {
      for (int j = 0; j + 2 < m; j++)
      {
        int sum = (grid[i][j + 2] + grid[i + 1][j + 1] - grid[i + 1][j] + grid[i + 2][j + 2]);
        if (j > 0)
        {
          sum -= (grid[i][j - 1] + grid[i + 2][j - 1]);
        }
        ans = max(ans, sum);
      }
    }
    return ans;
  }
};

int main()
{

  return 0;
}