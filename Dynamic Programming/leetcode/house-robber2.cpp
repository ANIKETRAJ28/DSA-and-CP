#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/house-robber-ii/description/

class Solution {
public:
    vector<int> dp1, dp2;
    // int ftd(vector<int> &v, int idx, vector<int> &dp){
    //     if(idx == v.size()-1) return v[idx];
    //     if(idx == v.size()-2) return max(v[idx], v[idx+1]);
    //     if(dp[idx] != -1) return dp[idx];
    //     return dp[idx] = max(v[idx] + ftd(v, idx+2, dp), ftd(v, idx+1, dp));
    // }

    int fbu(vector<int>& nums) {
        int n = nums.size();
        dp1.resize(n+1, -1);
        dp1[n-1] = nums[n-1];
        dp1[n-2] = max(nums[n-1], nums[n-2]);

        dp2.resize(n+1, -1);
        dp2[n-2] = nums[n-2];
        dp2[n-3] = max(nums[n-3], nums[n-2]);

        for(int i = n-3 ; i >= 1 ; i--) dp1[i] = max(nums[i] + dp1[i+2] ,dp1[i+1]);
        for(int i = n-4 ; i >= 0 ; i--) dp2[i] = max(nums[i] + dp2[i+2] ,dp2[i+1]);

        return max(dp1[1], dp2[0]);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        if(n == 3) return max(max(nums[0], nums[2]), nums[1]);
        return fbu(nums);
        // vector<int> dp1,dp2,nums1,nums2;
        // dp1.clear();
        // dp2.clear();
        // dp1.resize(nums.size(), -1);
        // dp2.resize(nums.size(), -1);
        // for(int i = 0 ; i < nums.size() ; i++){
        //     if(i != nums.size()-1) nums1.push_back(nums[i]);
        //     if(i != 0) nums2.push_back(nums[i]); 
        // }
        // return max(ftd(nums1, 0, dp1), ftd(nums2, 0, dp2));
    }
};

int main() {
    
    return 0;
}