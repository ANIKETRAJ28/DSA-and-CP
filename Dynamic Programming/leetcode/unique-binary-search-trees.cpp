#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/unique-binary-search-trees/description/

class Solution {
public:
    vector<int> dp;
    int ftd(int n) {
        if(n == 0 or n == 1) return 1;
        if(n == 2) return 2;
        if(dp[n] != -1) return dp[n];
        int res = 0;
        for(int i = 1 ; i <= n ; i++) {
            res += ftd(i-1)*ftd(n-i);
        }
        return dp[n] = res;
    } 
    int numTrees(int n) {
        // dp.resize(n+1, -1);
        // return ftd(n);
        dp.resize(n+2, 0);
        dp[0] = dp[1] = 1;
        dp[2] = 2;
        for(int i = 3 ; i <= n ; i++) {
            for(int k = 1 ; k <= i ; k++) {
                dp[i] += dp[k-1]*dp[i-k];
            }
        }
        return dp[n];
    }
};

int main() {
    
    return 0;
}