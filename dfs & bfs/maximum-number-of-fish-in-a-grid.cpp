#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/

class Solution
{
public:
  vector<int> dx = {0, 1, 0, -1};
  vector<int> dy = {1, 0, -1, 0};
  int findMaxFish(vector<vector<int>> &grid)
  {
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> qu;
    int maxFish = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j])
          qu.push({i, j});
        int ans = 0;
        while (!qu.empty())
        {
          pair<int, int> front = qu.front();
          int r = front.first;
          int c = front.second;
          qu.pop();
          ans += grid[r][c];
          grid[r][c] = 0;
          for (int d = 0; d < 4; d++)
          {
            int new_r = r + dx[d];
            int new_c = c + dy[d];
            if (new_r >= 0 && new_r < n && new_c >= 0 && new_c < m && grid[new_r][new_c])
            {
              qu.push({new_r, new_c});
            }
          }
        }
        maxFish = max(maxFish, ans);
      }
    }
    return maxFish;
  }
};

int main()
{

  return 0;
}