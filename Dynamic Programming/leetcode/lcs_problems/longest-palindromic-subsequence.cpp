#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/longest-palindromic-subsequence/submissions/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int dp[n+1][n+1];
        memset(dp, 0, sizeof(dp));
        string t = s;
        reverse(t.begin(), t.end());
        for(int i = 1 ; i <= n ; i++) {
            for(int j = 1 ; j <= n ; j++) {
                if(s[i-1] == t[j-1]) {
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
};

int main() {
    
    return 0;
}