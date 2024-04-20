#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/find-all-groups-of-farmland

class Solution {
public:
    #define pp pair<int, int>
    vector<int> dr = {-1,1,0,0};
    vector<int> dc = {0,0,1,-1};
    bool check(int n, int m, int r, int c) {
        return r >= 0 && c >= 0 && r < n && c < m;
    }
    vector<int> bfs(vector<vector<int>> &land, int r, int c) {
        int n = land.size(), m = land[0].size();
        queue<pp> qu;
        int row = r, col = c;
        qu.push({r, c});
        land[r][c] = 0;
        while(!qu.empty()) {
            auto el = qu.front();
            qu.pop();
            int cell_r = el.first;
            int cell_c = el.second;
            row = max(row, cell_r);
            col = max(col, cell_c);
            for(int d = 0 ; d < 4 ; d++) {
                if(check(n, m, cell_r+dr[d], cell_c+dc[d]) && land[cell_r+dr[d]][cell_c+dc[d]] == 1) {
                    qu.push({cell_r+dr[d], cell_c+dc[d]});
                    land[cell_r+dr[d]][cell_c+dc[d]] = 0;
                }
            }
        }
        return {r, c, row, col};
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        vector<vector<int>> ans;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(land[i][j] == 1) {
                    ans.push_back(bfs(land, i, j));
                }
            }
        }
        return ans;
    }
};

int main() {
    
    return 0;
}