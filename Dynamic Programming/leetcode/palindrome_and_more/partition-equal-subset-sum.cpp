#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/partition-equal-subset-sum/submissions/

class Solution {
public:
    // vector<vector<int>> dp;
    vector<vector<bool>> dp;
    bool ftd(vector<int>& nums, int i, int k) {
        int n = nums.size();
        // base case
        if(i == n) return 0;
        if(k == 0) return 1;
        if(dp[i][k] != -1) return dp[i][k];
        if(nums[i] <= k) {
            return dp[i][k] = ftd(nums, i+1, k-nums[i]) or ftd(nums, i+1, k);
        } else {
            return dp[i][k] = ftd(nums, i+1, k);
        }
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            sum += nums[i];
        }
        if(sum%2 != 0) return false;
        // dp.resize(201, vector<int> (20001, -1));
        // return ftd(nums, 0, sum/2);
        dp.resize(201, vector<bool> (20001, 0));
        for(int i = 0 ; i < nums.size() ; i++) {
            dp[i][0] = 1;
        }
        for(int i = nums.size()-1 ; i >= 0 ; i--) {
            for(int j = 1 ; j <= sum/2 ; j++) {
                if(nums[i] <= j) {
                    dp[i][j] = dp[i+1][j-nums[i]] or dp[i+1][j];
                } else {
                    dp[i][j] = dp[i+1][j];
                }
            }
        }
        return dp[0][sum/2];
    }
};

int main() {
    
    return 0;
}