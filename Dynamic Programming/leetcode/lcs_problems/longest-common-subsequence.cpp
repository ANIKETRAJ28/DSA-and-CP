#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/longest-common-subsequence/

class Solution {
public:

    vec<vec<int>> dp;

    int ftd(string &s1, string &s2, int i, int j){
        int n = s1.size();
        int m = s2.size();
        // base case
        if(i == n || j == m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) return dp[i][j] = 1 + ftd(s1, s2, i+1, j+1);
        else{
            return dp[i][j] = max(ftd(s1, s2, i+1, j), ftd(s1, s2, i, j+1));
        }
    }

    int fbu(string &s1, string &s2){
        dp.resize(1005, vec<int> (1005, 0));
        int n = s1.size();
        int m = s2.size();
        dp.resize(n+1, vector<int> (m+1, 0));
        for(int i = 1 ; i <= n ; i++) {
            for(int j = 1 ; j <= m ; j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }

    int longestCommonSubsequence(string s1, string s2) {
        // dp.resize(1005, vector<int> (1005, -1));
        // return ftd(s1, s2, 0, 0);
        return fbu(s1, s2);
    }
};

int main(){
    
    return 0;
}
