#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/jump-game/description/

class Solution
{
public:
  vector<int> dp;
  bool ftd(vector<int> &nums, int i)
  {
    int n = nums.size();
    if (i >= n - 1)
      return true;
    if (dp[i] != -1)
      return dp[i];
    if (nums[i] == 0)
      return false;
    bool canReach = false;
    for (int j = i + 1; j <= i + nums[i]; j++)
    {
      if (j >= n - 1)
        return dp[i] = true;
      canReach = canReach || ftd(nums, j);
    }
    return dp[i] = canReach;
  }
  bool canJump(vector<int> &nums)
  {
    int n = nums.size();
    dp.resize(n, -1);
    return ftd(nums, 0);
  }
};

int main()
{

  return 0;
}