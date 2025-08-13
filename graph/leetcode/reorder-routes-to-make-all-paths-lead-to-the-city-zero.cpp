#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

class Solution
{
public:
  int bfs(vector<list<int>> &graph)
  {
    int n = graph.size();
    queue<int> qu;
    unordered_set<int> visited;
    qu.push(0);
    int ans = 0;
    while (!qu.empty())
    {
      int parent = qu.front();
      qu.pop();
      visited.insert(abs(parent));
      for (auto neig : graph[abs(parent)])
      {
        if (visited.count(abs(neig)))
          continue;
        if ((parent >= 0 && neig > 0) || (parent < 0 && neig > 0))
          ans++;
        qu.push(neig);
      }
    }
    return ans;
  }
  int minReorder(int n, vector<vector<int>> &connections)
  {
    vector<list<int>> graph(n);
    int m = connections.size();
    for (int i = 0; i < m; i++)
    {
      int src = connections[i][0];
      int dst = connections[i][1];
      graph[src].push_back(dst);
      graph[dst].push_back(-src);
    }

    return bfs(graph);
  }
};

int main()
{

  return 0;
}