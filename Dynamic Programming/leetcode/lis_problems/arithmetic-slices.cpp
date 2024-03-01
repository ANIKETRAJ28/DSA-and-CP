#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/arithmetic-slices/description/

class Solution {
public:
    vector<int> dp;
    int ftd(vector<int>& nums, int i) {
        // base case
        if(i <= 1) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = 0;
        if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) ans = 1 + ftd(nums, i-1);
        return dp[i] = ans;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        // dp.resize(nums.size()+1, -1);
        // for(int i = 2 ; i < nums.size() ; i++) {
        //     ans += ftd(nums, i);
        // }
        // return ans;
        dp.resize(nums.size()+1, 0);
        for(int i = 2 ; i < nums.size() ; i++) {
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                dp[i] = 1 + dp[i-1];
            }
        }
        for(int i = 0 ; i < nums.size() ; i++) {
            ans += dp[i];
        }
        return ans;
    }
};

int main(){
    
    return 0;
}