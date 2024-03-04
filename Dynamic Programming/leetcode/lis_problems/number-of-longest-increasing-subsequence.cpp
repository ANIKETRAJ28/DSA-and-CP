#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), cnt(n, 1);
        for(int i = 1 ; i < n ; i++) {
            for(int j = 0 ; j < i ; j++) {
                if(nums[i] > nums[j]) {
                    if(dp[j] + 1 > dp[i]) {
                        dp[i] = 1 + dp[j];
                        cnt[i] = cnt[j];
                    }
                    else if(dp[j] + 1 == dp[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
        }
        int maxi = 0;
        for(int i = 0 ; i < n ; i++) {
            maxi = max(maxi, dp[i]);
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
            if(dp[i] == maxi) ans += cnt[i];
        }
        return ans;
    }
};

int main() {
    
    return 0;
}