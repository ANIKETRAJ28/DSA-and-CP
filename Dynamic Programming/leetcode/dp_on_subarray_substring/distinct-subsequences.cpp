#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/distinct-subsequences/description/

class Solution {
public:
    unsigned long long dp[1005][1005];
    int ftd(string &s, string &t, string str, int i, int j) {
        int n = s.size();
        int m = t.size();
        if(j == m) return 1;
        if(i == n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        ans += ftd(s, t, str, i+1, j);
        if(s[i] == t[j]) ans += ftd(s, t, str+s[i], i+1, j+1);
        return dp[i][j] = ans;
    }
    int numDistinct(string s, string t) {
        // memset(dp, -1, sizeof(dp));
        // return ftd(s, t, "", 0, 0);
        int n = s.size();
        int m = t.size();
        memset(dp, 0, sizeof(dp));
        for(int i = 0 ; i <= n ; i++) {
            dp[i][m] = 1;
        }
        for(int i = n-1 ; i >= 0 ; i--) {
            for(int j = m-1 ; j >= 0 ; j--) {
                dp[i][j] = dp[i+1][j];
                if(s[i] == t[j]) dp[i][j] += dp[i+1][j+1];
            }
        }
        return dp[0][0];
    }
};

int main() {
    
    return 0;
}