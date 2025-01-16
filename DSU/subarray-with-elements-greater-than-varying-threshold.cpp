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
  int mx = 1;
  int find(int x, vector<int> &parent)
  {
    return parent[x] == x ? x : find(parent[x], parent);
  }
  void Union(int a, int b, vector<int> &parent, vector<int> &size)
  {
    a = find(a, parent);
    b = find(b, parent);
    if (a == b)
      return;
    if (a >= b)
    {
      size[a] += size[b];
      parent[b] = a;
      mx = max(mx, size[a]);
    }
    else
    {
      size[b] += size[a];
      parent[a] = b;
      mx = max(mx, size[b]);
    }
  }
  int validSubarraySize(vector<int> &nums, int threshold)
  {
    int n = nums.size();
    vector<pair<int, int>> val_idx;
    for (int i = 0; i < n; i++)
      val_idx.push_back({nums[i], i + 1});
    sort(val_idx.begin(), val_idx.end());

    vector<bool> active(n + 1, false);
    int k = 1;
    vector<int> size(n + 1, 1), parent(n + 1);
    for (int i = 0; i <= n; i++)
      parent[i] = i;

    for (int j = n - 1; j >= 0 && k <= n;)
    {
      double k_threashold = (double)threshold / k;
      while (j >= 0 && (double)val_idx[j].first > k_threashold)
      {
        int idx = val_idx[j].second;
        active[idx] = true;
        if (active[idx - 1])
          Union(idx, idx - 1, parent, size);
        if (active[idx + 1])
          Union(idx, idx + 1, parent, size);
        j--;
      }
      if (j < n - 1 && mx >= k)
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