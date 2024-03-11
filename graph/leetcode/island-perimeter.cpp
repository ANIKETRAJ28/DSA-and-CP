#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/island-perimeter/description/

class Solution {
public:
    int ans = 0;
    int n, m;
    vector<vector<int>> graph;
    vector<int> dr = {-1, 0, 0, 1};
    vector<int> dc = {0, -1, 1, 0};

    bool check(int r, int c) {
        if(r >= 0 and r < n and c >= 0 and c < m and graph[r][c] != 0) return 1;
        return 0;
    }
    
    void dfs(int r, int c) {
        graph[r][c] = -1;
        for(int d = 0 ; d < 4 ; d++) {
            if(check(r+dr[d], c+dc[d])) {
                if(graph[r+dr[d]][c+dc[d]] == 1) dfs(r+dr[d], c+dc[d]);
            } else {
                ans += 1;
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        graph = grid;
        int r = -1, c = -1;
        for(int i = 0 ; i < n ; i++) {
            bool flag = true;
            for(int j = 0 ; j < m ; j++) {
                if(grid[i][j] == 1) {
                    r = i; c = j; flag = false; break;
                }
            }
            if(!flag) break;
        }
        dfs(r, c);
        return ans;
    }
};

int main() {
    
    return 0;
}