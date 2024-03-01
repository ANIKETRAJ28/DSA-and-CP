#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/longest-increasing-subsequence/submissions/

class Solution {
public:
    vector<int> dp;
    int ftd(vector<int>& nums, int i) {
        // base case
        if(i == 0) return 1;
        if(dp[i] != -1) return dp[i];
        int ans = INT_MIN;
        for(int j = 0 ; j < i ; j++) {
            if(nums[j] < nums[i]) {
                ans = max(ans, ftd(nums, j));
            }
        }
        if(ans == INT_MIN) return 1;
        return dp[i] = ans+1;
    }
    int lengthOfLIS(vector<int>& nums) {
        // dp.resize(2501, -1);
        // int ans = INT_MIN;
        // for(int i = 0 ; i < nums.size() ; i++) {
        //     ans = max(ans, ftd(nums, i));
        // }
        // return ans;
        dp.resize(2501, 1);
        dp[0] = 1;
        int ans = 1;
        for(int i = 1 ; i < nums.size() ; i++) {
            for(int j = 0 ; j < i ; j++) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

int main() {
    
    return 0;
}