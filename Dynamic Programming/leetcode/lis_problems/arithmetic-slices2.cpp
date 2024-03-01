#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/arithmetic-slices-ii-subsequence/submissions/


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<ll, ll>> dp(n);
        int ans = 0;
        for(int i = 1 ; i < n ; i++) {
            for(int j = 0 ; j < i ; j++) {
                ll diff = (ll)nums[i] - (ll)nums[j];
                if(dp[j].find(diff) != dp[j].end()) {
                    ans += dp[j][diff];
                }
                dp[i][diff] += dp[j][diff]+1;
            }
        }
        
        return ans;
    }
};

int main() {
    
    return 0;
}