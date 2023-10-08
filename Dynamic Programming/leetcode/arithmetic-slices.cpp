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
    int ftd(vector<int> &arr, int i){
        // base case
        if(i <= 1) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = 0;
        if(arr[i] - arr[i-1] == arr[i-1] - arr[i-2]) ans = 1 + ftd(arr, i-1);
        return dp[i] = ans;
    }

    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        // if(n < 3) return 0;
        // dp.resize(n, 0);
        // for(int i = 2 ; i < n ; i++){
        //     if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2])
        //     dp[i] = 1 + dp[i-1];
        // }
        // int ans = 0;
        // for(int i = 0 ; i < n ; i++) ans += dp[i];
        // return ans;
        dp.clear();
        dp.resize(n, -1);
        ftd(nums, n-1);
        int ans = 0;
        for(int i = 2 ; i < n ; i++){
            ans += ftd(nums, i);
        }
        cout<<"\n";
        return ans;
    }
};

int main(){
    
    return 0;
}