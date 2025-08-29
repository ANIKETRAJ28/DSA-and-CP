#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description/

class Solution
{
public:
  vector<int> parent, rank, weight;
  int find(int a)
  {
    return parent[a] = parent[a] == a ? a : find(parent[a]);
  }
  void Union(int a, int b, int w)
  {
    a = find(a);
    b = find(b);
    if (rank[b] > rank[a])
      swap(a, b);
    parent[b] = a;
    rank[a]++;
    weight[a] = min(weight[a], min(weight[b], w));
  }
  int minScore(int n, vector<vector<int>> &roads)
  {
    int m = roads.size();
    parent.resize(n + 1);
    rank.resize(n + 1, 1);
    weight.resize(n + 1, INT_MAX);
    for (int i = 0; i < n; i++)
    {
      parent[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
      Union(roads[i][0], roads[i][1], roads[i][2]);
    }
    int par = find(0);
    return weight[par];
  }
};

int main()
{

  return 0;
}