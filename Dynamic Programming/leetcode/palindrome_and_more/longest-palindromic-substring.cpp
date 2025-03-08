#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/longest-palindromic-substring/description/

class Solution {
public:
    int dp[1005][1005];
    // fbu
    bool check(int i, int j, string &s) {
        while(i < j) {
            if(dp[i][j] != -1) return dp[i][j];
            if(s[i] != s[j]) return dp[i][j] = false;
            i++;
            j--;
        }
        return dp[i][j] = true;
    }
    // ftd
    bool check(int i, int j, string &s) {
        int n = s.size();
        // base case
        if(i > j) return true;
        if(dp[i][j] != -1) return dp[i][j];
        
        return s[i] == s[j] and check(i+1, j-1, s);
    }
    string longestPalindrome(string s) {
        memset(dp, -1, sizeof(dp));
        int strt = 0;
        int maxlen = 1;
        int n = s.size();
        for(int i = 0 ; i  < n ; i++) {
            for(int j = i ; j < n ; j++) {
                if(check(i, j, s)) {
                    if(j-i+1 > maxlen) {
                        strt = i;
                        maxlen = j-i+1;
                    }
                }
            }
        }
        return s.substr(strt, maxlen);
    }
};

int main() {
    
    return 0;
}