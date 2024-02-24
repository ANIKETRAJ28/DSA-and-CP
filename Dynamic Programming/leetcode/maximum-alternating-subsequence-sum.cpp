#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/maximum-alternating-subsequence-sum/description/

class Solution {
public:
    vector<vector<long long>> dp;
    long long ftd(vector<int>& nums, int i, bool pos) {
        int n = nums.size();
        // base case
        if(i == n) return 0;
        if(dp[i][pos] != -1) return dp[i][pos];
        long long ans = 0;
        // even
        if(pos) {
            // pick
            ans = max(ans, nums[i] + ftd(nums, i+1, false));
            // not pick
            ans = max(ans, ftd(nums, i+1, pos));
        }
        // odd
        else {
            // pick
            ans = max(ans, ftd(nums, i+1, true) - nums[i]);
            // not pick
            ans = max(ans, ftd(nums, i+1, pos)); 
        }
        return dp[i][pos] = ans;
    }
    long long maxAlternatingSum(vector<int>& nums) {
        dp.resize(100005, vector<long long>(3, -1));
        return ftd(nums, 0, true);
    }
};

int main() {
    
    return 0;
}