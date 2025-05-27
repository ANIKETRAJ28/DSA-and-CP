#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/out-of-boundary-paths/description/

class Solution
{
public:
#define mod 1000000007
  vector<int> dx = {-1, 1, 0, 0};
  vector<int> dy = {0, 0, -1, 1};
  int dp[51][51][51];
  int find(int m, int n, int maxMove, int startRow, int startColumn)
  {
    if (startRow < 0 || startRow == m || startColumn < 0 || startColumn == n)
      return 1;
    if (maxMove == 0)
      return 0;
    if (dp[startRow][startColumn][maxMove] != -1)
      return dp[startRow][startColumn][maxMove];
    int ans = 0;
    for (int d = 0; d < 4; d++)
    {
      ans = (ans % mod + find(m, n, maxMove - 1, startRow + dx[d], startColumn + dy[d]) % mod) % mod;
    }
    return dp[startRow][startColumn][maxMove] = ans % mod;
  }
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
  {
    memset(dp, -1, sizeof(dp));
    return find(m, n, maxMove, startRow, startColumn);
  }
};

int main()
{

  return 0;
}