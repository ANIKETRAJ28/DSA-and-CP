#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1

// User function Template for C++

class Solution
{
public:
  vector<int> dx = {0, 1, 0, -1};
  vector<int> dy = {1, 0, -1, 0};
  vector<char> dr = {'R', 'D', 'L', 'U'};
  void bfs(vector<vector<int>> &grid, int i, int j, unordered_set<string> &st)
  {
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> qu;
    qu.push({i, j});
    grid[i][j] = 0;
    string ans = "";
    while (!qu.empty())
    {
      pair<int, int> curr = qu.front();
      int r = curr.first;
      int c = curr.second;
      qu.pop();
      ans += 'S';
      for (int d = 0; d < 4; d++)
      {
        int new_r = r + dx[d];
        int new_c = c + dy[d];
        if (new_r >= 0 && new_r < n && new_c >= 0 && new_c < m && grid[new_r][new_c])
        {
          qu.push({new_r, new_c});
          grid[new_r][new_c] = 0;
          ans += dr[d];
        }
      }
      ans += 'E';
    }
    st.insert(ans);
  }
  int countDistinctIslands(vector<vector<int>> &grid)
  {
    // code here
    int n = grid.size();
    int m = grid[0].size();
    unordered_set<string> st;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j])
          bfs(grid, i, j, st);
      }
    }
    return st.size();
  }
};

int main()
{

  return 0;
}