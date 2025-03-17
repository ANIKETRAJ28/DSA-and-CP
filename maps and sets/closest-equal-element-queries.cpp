#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/closest-equal-element-queries/description/

class Solution
{
public:
  vector<int> solveQueries(vector<int> &nums, vector<int> &queries)
  {
    int n = nums.size();
    int m = queries.size();
    vector<int> pre(n, -1);
    unordered_map<int, int> lastOcc, frstOcc, currOcc;
    for (int i = n - 1; i >= 0; i--)
    {
      if (lastOcc.find(nums[i]) == lastOcc.end())
        lastOcc[nums[i]] = i;
      frstOcc[nums[i]] = i;
    }
    for (int i = n - 1; i >= 0; i--)
    {
      if (currOcc.find(nums[i]) == currOcc.end())
      {
        if (frstOcc[nums[i]] == i)
          continue;
        pre[i] = min(i - frstOcc[nums[i]], n - i + frstOcc[nums[i]]);
      }
      else
      {
        pre[i] = currOcc[nums[i]] - i;
        if (frstOcc[nums[i]] != i)
          pre[i] = pre[i] = min(pre[i], i - frstOcc[nums[i]]);
        pre[i] = min(pre[i], i + n - lastOcc[nums[i]]);
      }
      currOcc[nums[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
      if (currOcc[nums[i]] != i)
      {
        pre[i] = min(pre[i], i - currOcc[nums[i]]);
        currOcc[nums[i]] = i;
      }
    }
    vector<int> ans(m);
    for (int i = 0; i < m; i++)
    {
      ans[i] = pre[queries[i]];
    }
    return ans;
  }
};

int main()
{

  return 0;
}