#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/subarray-with-elements-greater-than-varying-threshold

class Solution
{
public:
  vector<int> parent, size;
  int mx = 1;

  int find(int a)
  {
    return parent[a] == a ? a : find(parent[a]);
  }

  void Union(int a, int b)
  {
    a = find(a);
    b = find(b);
    if (a == b)
      return;
    if (size[a] >= size[b])
    {
      parent[b] = a;
      size[a] += size[b];
      mx = max(mx, size[a]);
    }
    else
    {
      parent[a] = b;
      size[b] += size[a];
      mx = max(mx, size[b]);
    }
  }

  int validSubarraySize(vector<int> &nums, int threshold)
  {
    int n = nums.size();
    vector<pair<int, int>> val_idx;
    vector<bool> active(n + 1, 0);
    size.resize(n + 1, 1);
    parent.resize(n + 1);
    for (int i = 0; i < n; i++)
    {
      val_idx.push_back({nums[i], i + 1});
    }
    for (int i = 0; i <= n; i++)
      parent[i] = i;
    sort(val_idx.begin(), val_idx.end());
    int k = 1;
    for (int i = n - 1; i >= 0 && k <= n;)
    {
      double minGreatest = (double)threshold / k;
      while (i >= 0 && (double)val_idx[i].first > minGreatest)
      {
        int idx = val_idx[i].second;
        active[idx] = 1;
        if (active[idx - 1])
          Union(idx, idx - 1);
        if (active[idx + 1])
          Union(idx, idx + 1);
        i--;
      }
      if (i < n - 1 && mx >= k)
        return k;
      k++;
    }
    return -1;
  }
};

int main()
{

  return 0;
}