#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

// https://leetcode.com/problems/house-robber/description/

using namespace std;
template<typename T>
using vec = vector<T>;

class Solution {
public:
    vector<int> dp;
    int ftd(vector<int>& nums, int i) {
        int n = nums.size();
        if(i == n) return 0;
        if(i == n-1) return nums[i];
        if(dp[i] != -1) return dp[i];
        int sum = 0;
        sum = max(ftd(nums, i+1), nums[i] + ftd(nums, i+2));
        return dp[i] = sum;
    }
    int fbu(vector<int> &nums) {
        int n = nums.size();
        dp[n-1] = nums[n-1];
        dp[n-2] = max(nums[n-1], nums[n-2]);
        for(int i = n-3; i >= 0 ; i--) {
            dp[i] = max(nums[i] + dp[i+2], dp[i+1]);
        }
        return dp[0];
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        dp.resize(nums.size()+1, -1);
        // return ftd(nums, 0);
        return fbu(nums);
    }
};

int main() {
    
    return 0;
}