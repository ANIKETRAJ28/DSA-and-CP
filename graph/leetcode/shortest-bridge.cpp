#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/shortest-bridge/description/

class Solution {
public:
    vector<int> dr = {-1, 0, 0, 1};
    vector<int> dc = {0, -1, 1, 0};
    int shortestBridge(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        set<pair<int, int>> visited;
        queue<pair<int, int>> qu;
        bool flag = true;
        for(int r = 0 ; r < row ; r++) {
            for(int c = 0 ; c < col ; c++) {
                if(grid[r][c] == 1) {
                    qu.push({r, c});
                    visited.insert({r, c});
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
        while(not qu.empty()) {
            auto cell = qu.front();
            qu.pop();
            int r = cell.first;
            int c = cell.second;
            for(int d = 0 ; d < 4 ; d++) {
                int new_r = r + dr[d];
                int new_c = c + dc[d];
                if(new_r < 0 or new_c < 0 or new_r >= row or new_c >= col  or grid[new_r][new_c] == 0 or visited.find({new_r, new_c}) != visited.end()) continue;
                qu.push({new_r, new_c});
                visited.insert({new_r, new_c});
            }
        }
        for(auto el : visited) {
            qu.push({el.first, el.second});
        }
        int level = 0;
        while(not qu.empty()) {
            int l = qu.size();
            while(l--) {
                auto cell = qu.front();
                qu.pop();
                int r = cell.first;
                int c = cell.second;
                for(int d = 0 ; d < 4 ; d++) {
                    int new_r = r + dr[d];
                    int new_c = c + dc[d];
                    if(new_r < 0 or new_c < 0 or new_r >= row or new_c >= col or visited.find({new_r, new_c}) != visited.end()) continue;
                    if(grid[new_r][new_c] == 1) return level;
                    qu.push({new_r, new_c});
                    visited.insert({new_r, new_c});
                }
            }
            level++;
        }
        return -1;
    }
};

int main() {
    
    return 0;
}