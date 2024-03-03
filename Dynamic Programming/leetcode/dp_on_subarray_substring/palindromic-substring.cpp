#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/palindromic-substrings/description/

class Solution {
public:
    int dp[1005][1005];
    // fbu
    bool check(string &s, int i, int j) {
        while(i < j) {
            if(dp[i][j] != -1) return dp[i][j];
            if(s[i] != s[j]) return dp[i][j] = false;
            i++;
            j--;
        }
        return dp[i][j] = true;
    }
    // ftd
    bool check(string &s, int i, int j) {
        int n = s.size();
        // base case
        if(i > j) return true;
        if(dp[i][j] != -1) return dp[i][j];
        
        return s[i] == s[j] and check(s, i+1, j-1);
    } 
    int countSubstrings(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        int cnt = 0;
        for(int i = 0 ; i < n ; i++) {
            for(int j = i ; j < n ; j++) {
                cnt += check(s, i, j);
            }
        }
        return cnt;
    }
};

int main() {
    
    return 0;
}