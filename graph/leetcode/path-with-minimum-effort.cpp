#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/path-with-minimum-effort/description/

class Solution {
public:
    vector<int> dr = {1, 0, -1, 0};
    vector<int> dc = {0, 1, 0, -1};
    bool check(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<bool>> vis(n, vector<bool> (m, 0));
        vector<vector<int>> dis(n, vector<int> (m, INT_MAX));
        pq.push({0,0,0});
        vis[0][0] = 1;
        dis[0][0] = 0;
        while(!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();
            int wts = curr[0], row = curr[1], col = curr[2];
            vis[row][col] = 1;
            for(int d = 0 ; d < 4 ; d++) {
                int new_r = row+dr[d];
                int new_c = col+dc[d];
                if(!check(new_r, new_c, n, m)) continue;
                if(vis[new_r][new_c]) continue;
                int maxDiff = max(wts, abs(heights[row][col]-heights[new_r][new_c]));
                if(maxDiff < dis[new_r][new_c]) {
                    dis[new_r][new_c] = maxDiff;
                    pq.push({maxDiff, new_r, new_c});
                }
            }
        }
        return dis[n-1][m-1];
    }
};

int main() {
    
    return 0;
}