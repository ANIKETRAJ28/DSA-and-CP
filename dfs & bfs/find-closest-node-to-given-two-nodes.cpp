#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/find-closest-node-to-given-two-nodes

class Solution
{
public:
  void find(vector<int> &edges, unordered_map<int, int> &mp, int node, int cnt)
  {
    int n = edges.size();
    if (mp.find(node) != mp.end())
      return;
    mp[node] = cnt;
    if (edges[node] != -1)
      find(edges, mp, edges[node], cnt + 1);
  }
  int closestMeetingNode(vector<int> &edges, int node1, int node2)
  {
    unordered_map<int, int> mp1, mp2;
    find(edges, mp1, node1, 0);
    find(edges, mp2, node2, 0);
    int ans = INT_MAX;
    int diff = INT_MAX;
    for (auto el : mp1)
    {
      if (mp2.find(el.first) == mp2.end())
        continue;
      int val1 = mp1[el.first];
      int val2 = mp2[el.first];
      if (max(val1, val2) < diff)
      {
        diff = max(val1, val2);
        ans = el.first;
      }
      else if (max(val1, val2) == diff)
      {
        ans = min(ans, el.first);
      }
    }
    return ans == INT_MAX ? -1 : ans;
  }
};

int main()
{

  return 0;
}