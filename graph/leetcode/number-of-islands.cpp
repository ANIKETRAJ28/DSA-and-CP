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

    vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    bool check(vector<vector<char>>& grid, int i, int j){
        int n = grid.size();
        int m = grid[0].size();

        return (i >= 0 && j >= 0 && i < n && j < m && grid[i][j] == '1');
    }

    void dfs(vector<vector<char>>& grid, int i, int j){
        int n = grid.size();
        int m = grid[0].size();

        if(not check(grid, i, j)) return;
        grid[i][j] = '0';
        for(int d = 0 ; d < 4 ; d++){
            dfs(grid, i+dir[d].first, j+dir[d].second);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        // dfs
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
        // bfs
        queue<pair<int, int>> qu;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                // sea section
                if(grid[i][j] == '0') continue;
                qu.push({i, j});
                grid[i][j] = '0';
                ans++;
                while(not qu.empty()){
                    auto ele = qu.front();
                    qu.pop();
                    int r = ele.first;
                    int c = ele.second;
                    for(int d = 0 ; d < 4 ; d++){
                        if(check(grid, r + dir[d].first, c + dir[d].second)){
                            qu.push({r + dir[d].first, c + dir[d].second});
                            grid[r + dir[d].first][c + dir[d].second] = '0';
                        }
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