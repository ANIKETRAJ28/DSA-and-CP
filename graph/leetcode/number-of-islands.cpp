#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/number-of-islands/

class Solution {
public:

    void dfs(vec<vec<char>>& grid, int i, int j){
        int n = grid.size();
        int m = grid[0].size();
        // base case
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(grid, i+1, j);
        dfs(grid, i, j+1);
        dfs(grid, i-1, j);
        dfs(grid, i, j-1);
    }

    int numIslands(vec<vec<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        // for(int i = 0 ; i < n ; i++){
        //     for(int j = 0 ; j < m ; j++){
        //         if(grid[i][j] == '1'){
        //             dfs(grid, i, j);
        //             ans++;
        //         }
        //     }
        // }

        queue<pair<int, int>> qu;
        for(int r = 0 ; r < n ; r++){
            for(int c = 0 ; c < m ; c++){
                if(grid[r][c] == '0') continue;
                ans++;
                grid[r][c] = '0';
                qu.push({r, c});
                while(not qu.empty()){
                    auto curr = qu.front();
                    qu.pop();
                    int row = curr.first;
                    int col = curr.second;
                    // top
                    if(row-1 >= 0 and grid[row-1][col] == '1'){
                        qu.push({row-1, col});
                        grid[row-1][col] = '0';
                    }
                    // left
                    if(col-1 >= 0 and grid[row][col-1] == '1'){
                        qu.push({row, col-1});
                        grid[row][col-1] = '0';
                    }
                    // bottom
                    if(row+1 < n and grid[row+1][col] == '1'){
                        qu.push({row+1, col});
                        grid[row+1][col] = '0';
                    }
                    // right
                    if(col+1 < m and grid[row][col+1] == '1'){
                        qu.push({row, col+1});
                        grid[row][col+1] = '0';
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    
    return 0;
}