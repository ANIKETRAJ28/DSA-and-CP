#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/minimum-falling-path-sum-ii/submissions/

class Solution {
public:
    vector<vector<int>> dp;
    int ftd(vector<vector<int>>& v, int i, int j) {
        int n = v.size();
        // base case
        if(j >= n) return INT_MAX;
        if(i == n) return 0;
        if(dp[i][j] != INT_MAX) return dp[i][j];
        
        int ans = INT_MAX;
        for(int k = 0 ; k < n ; k++) {
            if(k == j) continue;
            ans = min(ans, ftd(v, i+1, k));
        }
        if(ans == INT_MAX) return v[i][j];
        ans += v[i][j];

        return dp[i][j] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        // int n = grid.size();
        // dp.resize(205, vector<int>(205, INT_MAX));
        // int ans = INT_MAX;
        // for(int i = 0 ; i < grid.size() ; i++) {
        //     ans = min(ans, ftd(grid, 0, i));
        // }
        int n = grid.size();
        dp.resize(205, vector<int>(205, 0));
        for(int j = 0 ; j < n ; j++) {
            dp[n-1][j] = grid[n-1][j];
        }
        for(int i = n-2 ; i >= 0 ; i--) {
            for(int j = 0 ; j < n ; j++) {
                int ans = INT_MAX;
                for(int k = 0 ; k < n ; k++) {
                    if(k== j) continue;
                    ans = min(ans, dp[i+1][k]);
                }
                ans += grid[i][j];
                dp[i][j] = ans;
            }
        }
        int ans = INT_MAX;
        for(int j = 0 ; j < n ; j++) {
            ans = min(ans, dp[0][j]);
        }
        return ans;
    }
};

int main() {
    
    return 0;
}