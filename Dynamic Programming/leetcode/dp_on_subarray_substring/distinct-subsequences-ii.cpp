#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/distinct-subsequences-ii/description/

class Solution {
public:
#define mod 1000000007
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        unordered_map<char, int> mp;
        for(int i = 1 ; i <= n ; i++) {
            char c = s[i-1];
            if(mp.find(c) == mp.end()) { // no duplicate letter found till now
                dp[i] = (2*dp[i-1]%mod + 1)%mod;
            } else {
                dp[i] = (2*dp[i-1]%mod - dp[mp[c]])%mod;
            }
            if(dp[i] < 0) dp[i] += mod;
            mp[c] = i-1;
        }
        return dp[n];
    }
};

int main() {
    
    return 0;
}