#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/minimize-maximum-of-array/

class Solution
{
public:
  bool canMake(vector<int> &nums, long long int val)
  {
    int n = nums.size();
    long long int cnt = 0;
    for (int i = n - 1; i >= 0; i--)
    {
      if (nums[i] + cnt <= val)
      {
        cnt = 0;
        continue;
      }
      cnt = nums[i] - val + cnt;
    }
    return cnt == 0;
  }
  int minimizeArrayValue(vector<int> &nums)
  {
    int n = nums.size();
    int lo = 0, hi = 1;
    for (int i = 0; i < n; i++)
    {
      hi = max(hi, nums[i]);
    }
    int ans = hi;
    while (lo <= hi)
    {
      int mid = lo + (hi - lo) / 2;
      if (canMake(nums, mid))
      {
        ans = mid;
        hi = mid - 1;
      }
      else
      {
        lo = mid + 1;
      }
    }
    return ans;
  }
};

int main()
{

  return 0;
}