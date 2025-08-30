#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/shortest-path-with-alternating-colors/description/

class Solution
{
public:
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
  {
    int redLen = redEdges.size();
    int blueLen = blueEdges.size();
    vector<list<pair<int, int>>> graph(n);
    // red edges with 0
    for (int i = 0; i < redLen; i++)
    {
      int src = redEdges[i][0];
      int dst = redEdges[i][1];
      graph[src].push_back({dst, 0});
    }
    // blue edges with 1
    for (int i = 0; i < blueLen; i++)
    {
      int src = blueEdges[i][0];
      int dst = blueEdges[i][1];
      graph[src].push_back({dst, 1});
    }
    // this vector represents for each node n the shortest distance with the red or blue edge
    vector<vector<int>> distance(n, vector<int>(2, INT_MAX));
    queue<pair<int, int>> qu;
    // pushing both the conditions (starting from blue edge as well as from the red edge)
    qu.push({0, 0}); // condition for red edge
    qu.push({0, 1}); // condition for blue edge
    // distance from 0 to 0 with red/blue edge is 0
    distance[0][0] = distance[0][1] = 0;
    while (!qu.empty())
    {
      auto el = qu.front();
      qu.pop();
      int par = el.first;
      int clr = el.second;
      for (auto el : graph[par])
      {
        if (el.second != clr && distance[el.first][!clr] > distance[par][clr] + 1)
        {
          distance[el.first][!clr] = 1 + distance[par][clr];
          qu.push(el);
        }
      }
    }
    vector<int> result(n);
    for (int i = 0; i < n; i++)
    {
      result[i] = min(distance[i][0], distance[i][1]);
      if (result[i] == INT_MAX)
        result[i] = -1;
    }
    return result;
  }
};

int main()
{

  return 0;
}