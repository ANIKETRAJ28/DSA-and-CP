#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/cherry-pickup/description/

class Solution {
public:
#define ll long long int
int n, m;
ll dp[55][55][55];
ll neg =-99999;

ll  ftd(vector<vector<int>>& grid, int i, int j, int x, int y) {
    // base case
    if(i >= n or j >= m or x >= n or y >= m or grid[i][j] == -1 or grid[x][y] == -1) return neg;
    if(i == n-1 and j == m-1) {
        return grid[i][j] == 1;
    }
    if(dp[i][j][x] != -1) return dp[i][j][x];

    ll res = neg;

    res = max(res, ftd(grid, i+1, j, x+1, y));     
    res = max(res, ftd(grid, i+1, j, x, y+1));    
    res = max(res, ftd(grid, i, j+1, x+1, y));    
    res = max(res, ftd(grid, i, j+1, x, y+1));

    if(res == neg) return dp[i][j][x] = neg;

    res += (grid[i][j] == 1);
    res += (grid[x][y] == 1);

    if(i == x and j == y and grid[i][j] == 1) res--;

    return dp[i][j][x] = res;
}

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        int ans = ftd(grid, 0, 0, 0 ,0);
        if(ans == neg) return 0;
        return ans;
    }
};

int main() {
    
    return 0;
}