#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/make-sum-divisible-by-p/

class Solution
{
public:
  int minSubarray(vector<int> &nums, int p)
  {
    int n = nums.size();
    int remainder = 0;
    int ans = n;
    for (int i = 0; i < n; i++)
    {
      remainder = (remainder + nums[i]) % p;
    }
    if (remainder == 0)
      return 0;
    unordered_map<int, int> mp;
    mp[0] = -1;
    int currRem = 0;
    for (int i = 0; i < n; i++)
    {
      currRem = (currRem + nums[i]) % p;
      int extra = (currRem - remainder + p) % p;
      if (mp.find(extra) != mp.end())
      {
        ans = min(ans, i - mp[extra]);
      }
      mp[currRem] = i;
    }
    return ans == n ? -1 : ans;
  }
};

int main()
{

  return 0;
}