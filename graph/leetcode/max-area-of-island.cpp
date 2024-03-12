#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/max-area-of-island/description/

class Solution {
public:
    vector<int> dr = {-1, 0, 0, 1};
    vector<int> dc = {0, -1, 1, 0};
    bool check(vector<vector<int>>& grid, int r, int c) {
        return (r >= 0 and c >= 0 and r < grid.size() and c < grid[0].size() and grid[r][c] == 1);
    }
    int dfs(vector<vector<int>>& grid, int r, int c) {
        grid[r][c] = 0;
        int ans = 1;
        for(int d = 0 ; d < 4 ; d++) {
            if(check(grid, r+dr[d], c+dc[d])) {
                ans += dfs(grid, r+dr[d], c+dc[d]);
            }
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0 ; i < grid.size() ; i++) {
            for(int j = 0 ; j < grid[0].size() ; j++) {
                if(grid[i][j]) {
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }
        return ans;
    }
};

int main() {
    
    return 0;
}