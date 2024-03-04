#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/delete-operation-for-two-strings/description/

class Solution {
public:
    int dp[505][505];
    int ftd(string &s1, string &s2, int i, int j) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(i == n1) return n2-j;
        if(j == n2) return n1-i;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) return dp[i][j] = ftd(s1, s2, i+1, j+1);
        return dp[i][j] = 1 + min(ftd(s1, s2, i+1, j), ftd(s1, s2, i, j+1));
    }
    int minDistance(string s1, string s2) {
        // memset(dp, -1, sizeof(dp));
        // return ftd(s1, s2, 0, 0);
        int n1 = s1.size(), n2 = s2.size();
        memset(dp, 0, sizeof(dp));
        for(int i = 0 ; i <= n1 ; i++) {
            dp[i][n2] = n1 - i;
        }
        for(int i = 0 ; i <= n2 ; i++) {
            dp[n1][i] = n2 - i;
        }
        for(int i = n1-1 ; i >= 0 ; i--) {
            for(int j = n2-1 ; j >= 0 ; j--) {
                if(s1[i] == s2[j]) {
                    dp[i][j] = dp[i+1][j+1];
                } else {
                    dp[i][j] = 1 + min(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};

int main() {
    
    return 0;
}