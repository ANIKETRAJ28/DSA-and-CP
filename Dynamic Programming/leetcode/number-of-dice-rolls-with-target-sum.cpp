#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/

class Solution {
public:
    #define mod 1000000007
    vector<vector<int>> dp;
    int ftd(int n, int k, int t) {
        // base case
        if(t == 0 and n == 0) return 1;
        if(n == 0 or t == 0) return 0;
        if(dp[n][t] != -1) return dp[n][t];
        int ans = 0;
        for(int i = 1 ; i <= k ; i++) {
            if(i > t) break;
            ans = (ans%mod + ftd(n-1, k, t-i)%mod)%mod;
        }
        return dp[n][t] = ans%mod;
    }

    int numRollsToTarget(int n, int k, int target) {
        // dp.resize(n+1, vector<int>(target+1, -1));
        // return ftd(n, k, target);
        dp.resize(n+1, vector<int>(target+1, 0));
        dp[0][0] = 1;
        for(int i = 1 ; i <= n ; i++) {
            for(int j = 1 ; j <= target ; j++) {
                int ans = 0;
                for(int l = 1 ; l <= k ; l++) {
                    if(j-l < 0) break;
                    ans = (ans%mod + dp[i-1][j-l]%mod)%mod;
                }
                dp[i][j] = ans;
            }
        }
        return dp[n][target];
    }
};

int main() {
    
    return 0;
}