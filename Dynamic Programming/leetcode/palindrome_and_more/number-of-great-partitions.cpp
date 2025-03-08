#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/number-of-great-partitions/description/

class Solution
{
public:
#define mod 1000000007
#define ll long long int

  vector<vector<ll>> dp;

  ll power(int a, int b)
  {
    if (b == 0)
      return 1;
    ll pow = power(a, b / 2) % mod;
    pow = (pow * pow) % mod;
    if (b % 2)
      pow = (pow * a) % mod;
    return pow;
  }

  ll ftd(vector<int> &nums, int i, int sum, int k)
  {
    int n = nums.size();
    if (sum >= k)
      return 0;
    if (i == n)
      return 1;
    if (dp[i][sum] != -1)
      return dp[i][sum];
    ll skip = ftd(nums, i + 1, sum, k);
    ll take = 0;
    if (sum + nums[i] <= k)
      take = ftd(nums, i + 1, sum + nums[i], k);
    return dp[i][sum] = (take + skip) % mod;
  }

  int countPartitions(vector<int> &nums, int k)
  {
    int n = nums.size();
    dp.resize(1005, vector<ll>(1005, -1));
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum = (sum + nums[i]) % mod;
    }
    if (sum < 2 * k)
      return 0;
    ll pow = power(2, n) % mod;
    return (pow - (2 * ftd(nums, 0, 0, k) % mod) + mod) % mod;
  }
};

int main()
{

  return 0;
}