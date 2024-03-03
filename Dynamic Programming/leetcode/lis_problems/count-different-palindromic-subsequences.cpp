#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/count-different-palindromic-subsequences/description/

class Solution {
public:
    #define mod 1000000007 
    int dp[1001][1001];
    int ftd(string &s, int i, int j) {
        // base case
        if(i > j) return 0;
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int res = 0;
        if(s[i] == s[j]) { // find the inner duplicates if possible
            int l = i+1, r = j-1;
            while(l <= r and s[l] != s[i]) l++; // inner duplicate found in left
            while(l <= r and s[r] != s[j]) r--; // inner duplicate found in right

            if(l < r) { // possibility of more duplicates between left and right
                res = ((2*(ftd(s, i+1, j-1)%mod))%mod-(ftd(s, l+1, r-1)%mod)%mod)%mod;
            }
            else if(l == r) { // the only duplicate present
                res = ((2*(ftd(s, i+1, j-1)%mod))%mod+1)%mod;
            }
            else { // no duplicates found
                res = ((2*(ftd(s, i+1, j-1)%mod))%mod+2)%mod;
            }
        }
        else {
            res = (ftd(s, i+1, j)%mod + ftd(s, i, j-1)%mod - ftd(s, i+1, j-1)%mod)%mod;
        }
        return dp[i][j] = res < 0 ? res+mod : res%mod;
    }
    int countPalindromicSubsequences(string s) {
        memset(dp, -1, sizeof(dp));
        return ftd(s, 0, s.size()-1);
    }
};

int main() {
    
    return 0;
}