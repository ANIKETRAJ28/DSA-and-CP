#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/length-of-the-longest-subsequence-that-sums-to-target/description/

class Solution
{
public:
    vector<vector<int>> dp;
    int f(vector<int> &nums, int i, int target)
    {
        if (target == 0)
        {
            return 0;
        }
        if (i >= nums.size())
            return INT_MIN;
        if (dp[i][target] != -1)
            return dp[i][target];
        int ans = f(nums, i + 1, target);
        if (target >= nums[i])
            ans = max(ans, 1 + f(nums, i + 1, target - nums[i]));
        return dp[i][target] = ans;
    }
    int lengthOfLongestSubsequence(vector<int> &nums, int target)
    {
        dp.resize(1005, vector<int>(1005, -1));
        int ans = f(nums, 0, target);
        if (ans < -1)
            return -1;
        return ans;
    }
};

int main()
{

    return 0;
}