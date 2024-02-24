#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/description/

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n+1, INT_MAX);
        // base case
        dp[0] = 0; 
        for(int i = 0 ; i <= n ; i++) {
            int ans = INT_MAX;
            int strt = max(0, i - ranges[i]);
            int end = min(n, i + ranges[i]);
            for(int j = strt ; j <= end ; j++) {
                ans = min(ans, dp[j]);
            }  
            if(ans != INT_MAX) {
                dp[end] = min(dp[end], ans+1);
            }
        }
        if(dp[n] == INT_MAX) return -1;
        return dp[n];
    }
};

int main() {
    
    return 0;
}