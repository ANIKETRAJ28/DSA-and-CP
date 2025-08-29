#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/as-far-from-land-as-possible/description/

class Solution
{
public:
  vector<int> dx = {0, -1, 0, 1};
  vector<int> dy = {-1, 0, 1, 0};
  bool isValid(vector<vector<int>> &grid, int i, int j)
  {
    int n = grid.size();
    return i >= 0 && i < n && j >= 0 && j < n;
  }
  int maxDistance(vector<vector<int>> &grid)
  {
    int n = grid.size();
    vector<vector<int>> matrix(n, vector<int>(n, INT_MAX));
    queue<pair<int, int>> qu;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j])
          matrix[i][j] = grid[i][j];
      }
    }
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j])
          matrix[i][j] = 0;
        for (int d = 0; d < 4; d++)
        {
          if (grid[i][j] && isValid(grid, i + dx[d], j + dy[d]) && grid[i + dx[d]][j + dy[d]] == 0)
          {
            qu.push({i, j});
            break;
          }
        }
      }
    }
    while (!qu.empty())
    {
      pair<int, int> front = qu.front();
      int r = front.first;
      int c = front.second;
      qu.pop();
      for (int d = 0; d < 4; d++)
      {
        int new_r = r + dx[d];
        int new_c = c + dy[d];
        if (isValid(grid, new_r, new_c) && matrix[new_r][new_c] == INT_MAX)
        {
          matrix[new_r][new_c] = 1 + matrix[r][c];
          qu.push({new_r, new_c});
        }
      }
    }
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        ans = max(ans, matrix[i][j]);
      }
    }
    return ans == INT_MAX || ans == 0 ? -1 : ans;
  }
};

int main()
{

  return 0;
}