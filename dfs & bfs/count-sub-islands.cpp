#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/count-sub-islands/description/

class Solution
{
public:
  vector<int> dx = {0, 1, 0, -1};
  vector<int> dy = {1, 0, -1, 0};
  int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
  {
    int n = grid1.size();
    int m = grid1[0].size();
    queue<pair<int, int>> qu;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        bool flag = false;
        if (grid2[i][j])
        {
          qu.push({i, j});
          grid2[i][j] = 0;
          flag = true;
        }
        while (!qu.empty())
        {
          auto [r, c] = qu.front();
          qu.pop();
          if (grid1[r][c] == 0)
            flag = false;
          for (int d = 0; d < 4; d++)
          {
            int new_r = r + dx[d];
            int new_c = c + dy[d];
            if (new_r >= 0 && new_r < n && new_c >= 0 && new_c < m && grid2[new_r][new_c])
            {
              qu.push({new_r, new_c});
              grid2[new_r][new_c] = 0;
            }
          }
        }
        ans += flag;
      }
    }
    return ans;
  }
};

int main()
{

  return 0;
}