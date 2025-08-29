#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/description/

class Solution
{
public:
  vector<vector<int>> graph;
  long long fuel = 0;
  long long findFuel(int src, int par, int seats)
  {
    int n = graph[src].size();
    long long totalPassengers = 0;
    for (int i = 0; i < n; i++)
    {
      if (graph[src][i] != par)
      {
        long long passengers = findFuel(graph[src][i], src, seats);
        totalPassengers += passengers;
        fuel += ceil((double)passengers / seats);
      }
    }
    return totalPassengers + 1;
  }
  long long minimumFuelCost(vector<vector<int>> &roads, int seats)
  {
    int n = roads.size();
    graph.resize(n + 1);
    for (int i = 0; i < n; i++)
    {
      int src = roads[i][0];
      int dst = roads[i][1];
      graph[src].push_back(dst);
      graph[dst].push_back(src);
    }
    findFuel(0, -1, seats);
    return fuel;
  }
};

int main()
{

  return 0;
}