#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/find-the-number-of-copy-arrays/

class Solution
{
public:
  int check(vector<int> &diff, vector<vector<int>> &bounds, int mid)
  {
    int n = bounds.size();
    for (int i = 0; i < n; i++)
    {
      if (mid + diff[i] < bounds[i][0])
        return -1;
      if (mid + diff[i] > bounds[i][1])
        return 1;
    }
    return 0;
  }

  int countArrays(vector<int> &original, vector<vector<int>> &bounds)
  {
    int n = original.size();
    vector<int> diff(n);
    for (int i = 1; i < n; i++)
    {
      diff[i] = diff[i - 1] + original[i] - original[i - 1];
    }
    int lo = bounds[0][0];
    int hi = bounds[0][1];
    int minDiff = -1, maxDiff = -1;
    // min diff
    while (lo <= hi)
    {
      int mid = lo + (hi - lo) / 2;
      int res = check(diff, bounds, mid);
      if (res == -1)
      {
        lo = mid + 1;
      }
      else
      {
        minDiff = mid;
        hi = mid - 1;
      }
    }
    if (minDiff == -1)
      return 0;
    lo = bounds[0][0];
    hi = bounds[0][1];
    // max diff
    while (lo <= hi)
    {
      int mid = lo + (hi - lo) / 2;
      int res = check(diff, bounds, mid);
      if (res == 1)
      {
        hi = mid - 1;
      }
      else
      {
        maxDiff = mid;
        lo = mid + 1;
      }
    }
    if (maxDiff == -1)
      return 0;
    return maxDiff - minDiff + 1;
  }
};

int main()
{

  return 0;
}