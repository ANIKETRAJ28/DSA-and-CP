#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/description/

class Solution {
public:
    #define mod 1000000007
    vector<vector<vector<int>>> dp;
    int ftd(vector<vector<int>> &grid, int i, int j, int sum, int k) {
        int n = grid.size();
        int m = grid[0].size();
        if(i >= n or j >= m) return 0;
        if(i == n-1 and j == m-1) {
            if((sum+grid[i][j])%k == 0) return 1;
            return 0;
        }
        if(dp[i][j][sum] != -1) return dp[i][j][sum];
        return dp[i][j][sum] = (ftd(grid, i+1, j, (sum+grid[i][j])%k, k)%mod + ftd(grid, i, j+1, (sum+grid[i][j])%k, k)%mod)%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        dp.resize(grid.size()+1, vector<vector<int>> (grid[0].size()+1, vector<int> (k+1, -1)));
        return ftd(grid, 0, 0, 0, k);
    }
};

int main() {
    
    return 0;
}