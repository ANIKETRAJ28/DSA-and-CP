#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/maximum-candies-allocated-to-k-children/

class Solution
{
public:
  bool canFulfill(vector<int> &candies, int candy, long long k)
  {
    int n = candies.size();
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
      ans += (long long)candies[i] / candy;
      if (ans >= k)
        return true;
    }
    return false;
  }
  int maximumCandies(vector<int> &candies, long long k)
  {
    int n = candies.size();
    int lo = 1, hi = -1;
    for (int i = 0; i < n; i++)
    {
      hi = max(hi, candies[i]);
    }
    int ans = 0;
    while (lo <= hi)
    {
      int mid = lo + (hi - lo) / 2;
      if (canFulfill(candies, mid, k))
      {
        ans = mid;
        lo = mid + 1;
      }
      else
      {
        hi = mid - 1;
      }
    }
    return ans;
  }
};

int main()
{

  return 0;
}