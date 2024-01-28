#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/unique-paths-iii/description

class Solution {
public:
    int cnt = 0, zero = 0;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    bool check(vector<vector<int>>& grid, int r, int c) {
        int n = grid.size();
        int m = grid[0].size();
        if(r < 0 or r >= n or c < 0 or  c >= m or grid[r][c] == -1) return false;
        return true;
    }
    void path(vector<vector<int>>& grid, int r, int c, int z) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[r][c] == 2) {
            if(z == zero)
            cnt++;
            return;
        }
        grid[r][c] = -1;
        for(int d = 0 ; d < 4 ; d++) {
            if(check(grid, r+dx[d], c+dy[d])) {
                path(grid, r+dx[d], c+dy[d], z+1);
            }
        }
        grid[r][c] = 0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int row = -1, col = -1;
        for(int i = 0 ; i  < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(grid[i][j] == 0) zero++;
                if(grid[i][j] == 1) {
                    row = i; col = j;
                }
            }
        }
        zero++;
        path(grid, row, col, 0);
        return cnt;
    }
};

int main(){
    
    return 0;
}