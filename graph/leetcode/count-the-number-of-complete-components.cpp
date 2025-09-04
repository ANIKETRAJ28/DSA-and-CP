#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/count-the-number-of-complete-components/

class Solution
{
public:
  vector<unordered_set<int>> node_edges;
  vector<int> parent, size;
  int find(int src)
  {
    return parent[src] = parent[src] == src ? src : find(parent[src]);
  }
  void Union(int src, int dst)
  {
    src = find(src);
    dst = find(dst);
    if (src == dst)
      return;
    if (size[dst] > size[src])
      swap(src, dst);
    parent[dst] = src;
    size[src] += size[dst];
  }
  int countCompleteComponents(int n, vector<vector<int>> &edges)
  {
    int m = edges.size();
    parent.resize(n);
    size.resize(n, 1);
    for (int i = 0; i < n; i++)
      parent[i] = i;
    node_edges.resize(n, {});
    for (int i = 0; i < m; i++)
    {
      int src = edges[i][0];
      int dst = edges[i][1];
      node_edges[src].insert(dst);
      node_edges[dst].insert(src);
      Union(src, dst);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      if (parent[i] == i)
      {
        int elements = size[i] - 1;
        if (elements != node_edges[i].size())
          continue;
        bool flag = true;
        for (auto el : node_edges[i])
        {
          if (node_edges[el].size() != elements)
          {
            flag = false;
            break;
          }
        }
        cnt += flag;
      }
    }
    return cnt;
  }
};

int main()
{

  return 0;
}