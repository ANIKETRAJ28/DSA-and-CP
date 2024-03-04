#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/

class Solution {
public:
    int dp[505][505];
    int ftd(string &s, int i, int j) {
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] != s[j]) return dp[i][j] = 1 + min(ftd(s, i+1, j), ftd(s, i, j-1));
        else return dp[i][j] = ftd(s, i+1, j-1);
    }
    int minInsertions(string s) {
        // memset(dp, -1, sizeof(dp));
        // return ftd(s, 0, s.size()-1);
        memset(dp, 0, sizeof(dp));
        int n = s.size();
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] != s[j]) {
                    dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1]);
                } else {
                    dp[i][j] = dp[i+1][j-1];
                }
            }
        }
        return dp[0][n-1];
    }
};

int main() {
    
    return 0;
}