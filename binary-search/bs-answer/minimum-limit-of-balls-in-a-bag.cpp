#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/

class Solution
{
public:
  bool canMake(vector<int> &nums, int k, int ops)
  {
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      ans += ceil((nums[i] - 1) / k);
      if (ans > ops)
        return false;
    }
    return true;
  }
  int minimumSize(vector<int> &nums, int maxOperations)
  {
    int n = nums.size();
    int lo = 1, hi = 1;
    for (int i = 0; i < n; i++)
    {
      hi = max(hi, nums[i]);
    }
    int ans = 0;
    while (lo <= hi)
    {
      int mid = lo + (hi - lo) / 2;
      if (canMake(nums, mid, maxOperations))
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