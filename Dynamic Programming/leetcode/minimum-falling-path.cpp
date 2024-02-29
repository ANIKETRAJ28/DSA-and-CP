#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/minimum-falling-path-sum/description/

class Solution {
public:
    vector<vector<int>> dp;
    int ftd(vector<vector<int>>& v, int i, int j) {
        int n = v.size();
        // base case
        if(j >= n or j < 0) return INT_MAX;
        if(i == n) return 0;
        if(dp[i][j] != INT_MAX) return dp[i][j];

        int ans = INT_MAX;
        ans = min(ans, ftd(v, i+1, j-1));
        ans = min(ans, ftd(v, i+1, j));
        ans = min(ans, ftd(v, i+1, j+1));
        ans += v[i][j];

        return dp[i][j] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // dp.resize(105, vector<int>(105, INT_MAX));
        // int ans = INT_MAX;
        // for(int i = 0 ; i < matrix.size() ; i++) {
        //     ans = min(ans, ftd(matrix, 0, i));
        // }
        int n = matrix.size();
        dp.resize(105, vector<int>(105, 0));
        for(int j = 0 ; j < n ; j++) {
            dp[n-1][j] = matrix[n-1][j];
        }
        for(int i = n-2 ; i >= 0 ; i--) {
            for(int j = 0 ; j < n ; j++) {
                int ans = INT_MAX;
                for(int k = -1 ; k < 2 ; k++) {
                    if(j+k < 0 or j+k >= n) continue;
                    ans = min(ans, dp[i+1][j+k]);
                }
                ans += matrix[i][j];
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