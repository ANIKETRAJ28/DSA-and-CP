#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/pacific-atlantic-water-flow/description/

class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    vector<vector<bool>> bfs(queue<pair<int, int>> &qu, vector<vector<int>> &h){
        int n = h.size();
        int m = h[0].size();
        vector<vector<bool>> visited(n, vector<bool> (m, 0));
        while(not qu.empty()){
            auto cell = qu.front();
            qu.pop();
            int r = cell.first;
            int c = cell.second;
            visited[r][c] = true;
            for(int d = 0 ; d < 4 ; d++){
                int new_r = r + dir[d][0];
                int new_c = c + dir[d][1];
                if(new_r < 0 || new_c < 0 || new_r >= n || new_c >= m) continue;
                if(visited[new_r][new_c] == 1) continue;
                if(h[new_r][new_c] < h[r][c]) continue;
                qu.push({new_r, new_c});
            }
        }
        return visited;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        queue<pair<int, int>> pacificbfs, atlanticbfs;
        for(int i = 0 ; i < n ; i++){
            pacificbfs.push({i, 0});
            atlanticbfs.push({i, m-1});
        }
        for(int i = 1 ; i < m ; i++){
            pacificbfs.push({0, i});
        }
        for(int i = 0 ; i < m-1 ; i++){
            atlanticbfs.push({n-1, i});
        }
        vector<vector<bool>> pacific = bfs(pacificbfs, heights);
        vector<vector<bool>> atlantic = bfs(atlanticbfs, heights);
        vector<vector<int>> ans;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(atlantic[i][j] == 1 and pacific[i][j] == 1) ans.push_back({i, j});
            }
        }
        return ans;
    }
};

int main(){
    
    return 0;
}