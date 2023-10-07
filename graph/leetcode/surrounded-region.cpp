#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/surrounded-regions/

class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    void solve(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> qu;
        vector<vector<bool>> vis(n, vector<bool> (m, 0)); 
        for(int i = 0 ; i < n ; i++){
            if(grid[i][0] == 'O'){
                qu.push({i, 0});
            }
            if(grid[i][m-1] == 'O'){
                qu.push({i, m-1});
            }
        }
        for(int i = 1 ; i < m-1 ; i++){
            if(grid[0][i] == 'O'){
                qu.push({0, i});
            }
            if(grid[n-1][i] == 'O'){
                qu.push({n-1, i});
            }
        }
        while(not qu.empty()){
            auto cell = qu.front();
            qu.pop();
            int r = cell.first;
            int c = cell.second;
            vis[r][c] = 1;
            for(int d = 0 ; d < 4 ; d++){
                int new_r = r + dir[d][0];
                int new_c = c + dir[d][1];
                if(new_r < 0 || new_r >= n || new_c < 0 || new_c >= m || grid[new_r][new_c] == 'X' || vis[new_r][new_c] == 1) continue;
                vis[new_r][new_c] = 1;
                qu.push({new_r, new_c});
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(vis[i][j] == 1) grid[i][j] = 'O';
                else{
                    if(grid[i][j] == 'O')grid[i][j] = 'X';
                }
            }
        }
        return;
    }
};

int main(){
    
    return 0;
}