#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/minimum-increment-operations-to-make-array-beautiful/

class Solution
{
public:
    vector<long long> dp;
    long long f(vector<int> &nums, int i, int k)
    {
        if (i >= nums.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        long long a = f(nums, i + 1, k);
        long long b = f(nums, i + 2, k);
        long long c = f(nums, i + 3, k);
        long long ans = min(a, min(b, c));
        if (k > nums[i])
            return dp[i] = k - nums[i] + ans;
        return dp[i] = ans;
    }

    long long minIncrementOperations(vector<int> &nums, int k)
    {
        dp.resize(100005, -1);
        long long ans = f(nums, 0, k);
        ans = min(ans, f(nums, 1, k));
        ans = min(ans, f(nums, 2, k));
        return ans;
    }
};

int main()
{

    return 0;
}