#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/

class Solution {
public:
    // right(1), left(2), down(3), up(4)
    vector<int> dr = {0, 0, 1, -1};
    vector<int> dc = {1, -1, 0, 0};
    bool check(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dis(n, vector<int> (m, INT_MAX));
        vector<vector<bool>> vis(n, vector<bool> (m, 0));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,0,0});
        dis[0][0] = 0;
        while(!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();
            int wts = curr[0];
            int row = curr[1];
            int col = curr[2];
            if(vis[row][col]) continue;
            vis[row][col] = 1;
            for(int d = 0 ; d < 4 ; d++) {
                int new_r = row+dr[d];
                int new_c = col+dc[d];
                if(check(new_r, new_c, n, m) && !vis[new_r][new_c]) {
                    if(d+1 == grid[row][col] and wts < dis[new_r][new_c]) {
                        pq.push({wts, new_r, new_c});
                        dis[new_r][new_c] = wts;
                    } else if(wts+1 < dis[new_r][new_c]) {
                        pq.push({wts+1, new_r, new_c});
                        dis[new_r][new_c] = wts+1;
                    }
                }
            }
        }
        return dis[n-1][m-1];
    }
};

int main() {
    
    return 0;
}