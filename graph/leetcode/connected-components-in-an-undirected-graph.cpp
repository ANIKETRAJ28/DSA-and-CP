#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1

class Solution
{
public:
  vector<int> parent;
  vector<unordered_set<int>> rank;
  int find(int a)
  {
    return parent[a] = parent[a] == a ? a : find(parent[a]);
  }
  void Union(int a, int b)
  {
    a = find(a);
    b = find(b);
    if (a == b)
      return;
    if (rank[b].size() > rank[a].size())
      swap(a, b);
    for (auto el : rank[b])
    {
      rank[a].insert(el);
    }
    parent[b] = a;
    return;
  }
  vector<vector<int>> getComponents(int V, vector<vector<int>> &edges)
  {
    // code here
    parent.resize(V);
    rank.resize(V);
    for (int i = 0; i < V; i++)
    {
      parent[i] = i;
      rank[i].insert(i);
    }
    for (int i = 0; i < edges.size(); i++)
    {
      int a = edges[i][0];
      int b = edges[i][1];
      Union(a, b);
    }
    vector<vector<int>> result;
    for (int i = 0; i < V; i++)
    {
      if (parent[i] == i)
      {
        vector<int> ans;
        for (auto el : rank[i])
        {
          ans.push_back(el);
        }
        sort(ans.begin(), ans.end());
        result.push_back(ans);
      }
    }
    return result;
  }
};

int main()
{

  return 0;
}