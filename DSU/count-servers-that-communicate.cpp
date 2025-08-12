#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/count-servers-that-communicate/

class Solution
{
public:
  vector<int> parent, rank;
  int find(int x)
  {
    return parent[x] = parent[x] == x ? x : find(parent[x]);
  }
  void Union(int a, int b)
  {
    a = find(a);
    b = find(b);
    if (a == b)
      return;
    if (rank[a] < rank[b])
      swap(a, b);
    parent[b] = a;
    rank[a] += rank[b];
  }
  int countServers(vector<vector<int>> &grid)
  {
    int n = grid.size();
    int m = grid[0].size();
    parent.resize(n);
    rank.resize(n, 0);
    for (int i = 0; i < n; i++)
    {
      parent[i] = i;
      for (int j = 0; j < m; j++)
      {
        rank[i] += grid[i][j];
      }
    }
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        for (int k = 0; k < m; k++)
        {
          if (grid[i][k] && grid[j][k])
          {
            Union(i, j);
          }
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      if (parent[i] == i && rank[i] > 1)
        ans += rank[i];
    }
    return ans;
  }
};

class Solution
{
public:
  int countServers(vector<vector<int>> &grid)
  {
    int n = grid.size();
    int m = grid[0].size();
    vector<int> rows(n);
    vector<int> col(m);
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j])
        {
          rows[i]++;
          col[j]++;
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] && (rows[i] > 1 || col[j] > 1))
          ans++;
      }
    }
    return ans;
  }
};

int main()
{

  return 0;
}