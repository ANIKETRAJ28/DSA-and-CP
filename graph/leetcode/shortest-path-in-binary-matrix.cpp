#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

// dijkstras
class Solution {
public:
    vector<int> dr = {-1, -1, -1, 0, 1, 1, 1, 0};
    vector<int> dc = {-1, 0, 1, 1, 1, 0, -1, -1};
    bool check(int i, int j, int n) {
        return i >= 0 && i < n && j >= 0 && j < n;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        int n = grid.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({1, 0, 0});
        vector<vector<bool>> vis(n, vector<bool> (n, 0));
        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
        dis[0][0] = 1;
        while(!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();
            int wts = curr[0];
            int row = curr[1];
            int col = curr[2];
            vis[row][col] = 1;
            for(int d = 0 ; d < 8 ; d++) {
                int new_r = row+dr[d];
                int new_c = col+dc[d];
                if(!check(new_r, new_c, n) || vis[new_r][new_c]) continue;
                if(grid[new_r][new_c] == 1) continue;
                if(wts+1 < dis[new_r][new_c]) {
                    dis[new_r][new_c] = wts+1;
                    pq.push({wts+1, new_r, new_c});
                }
            }
        }
        return dis[n-1][n-1] == INT_MAX ? -1 : dis[n-1][n-1];
    }
};

// dfs
class Solution {
public:
    vector<int> dr = {-1, -1, -1, 0, 1, 1, 1, 0};
    vector<int> dc = {-1, 0, 1, 1, 1, 0, -1, -1};
    bool check(int i, int j, int n) {
        return i >= 0 && i < n && j >= 0 && j < n;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        int n = grid.size();
        queue<vector<int>> qu;
        qu.push({1, 0, 0});
        vector<vector<bool>> vis(n, vector<bool> (n, 0));
        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
        dis[0][0] = 1;
        while(!qu.empty()) {
            vector<int> curr = qu.front();
            qu.pop();
            int wts = curr[0];
            int row = curr[1];
            int col = curr[2];
            vis[row][col] = 1;
            for(int d = 0 ; d < 8 ; d++) {
                int new_r = row+dr[d];
                int new_c = col+dc[d];
                if(!check(new_r, new_c, n) || vis[new_r][new_c]) continue;
                if(grid[new_r][new_c] == 1) continue;
                if(wts+1 < dis[new_r][new_c]) {
                    dis[new_r][new_c] = wts+1;
                    qu.push({wts+1, new_r, new_c});
                }
            }
        }
        return dis[n-1][n-1] == INT_MAX ? -1 : dis[n-1][n-1];
    }
};

int main() {
    
    return 0;
}