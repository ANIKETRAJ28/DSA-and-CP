#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/01-matrix/description/

class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> mat01(n, vector<int> (m, INT_MAX));
        queue<pair<int, int>> qu;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j] == 0){
                    qu.push({i, j});
                    mat01[i][j] = 0;
                }
            }
        }
        while(not qu.empty()){
            auto cell = qu.front();
            qu.pop();
            int r = cell.first;
            int c = cell.second;
            for(int d = 0 ; d < 4 ; d++){
                int new_r = r + dir[d][0];
                int new_c = c + dir[d][1];
                if(new_r < 0 || new_c < 0 || new_r >= n || new_c >= m) continue;
                if(mat01[new_r][new_c] != INT_MAX) continue;
                mat01[new_r][new_c] = 1 + mat01[r][c];
                qu.push({new_r, new_c});
            }
        }
        return mat01;
    }
};

class Solution {
public:
    vector<int> dr = {-1, 0, 0, 1};
    vector<int> dc = {0, -1, 1, 0};
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        queue<pair<int, int>> qu;
        set<pair<int, int>> visited;
        for(int r = 0 ; r < row ; r++) {    
            for(int c = 0 ; c < col ; c++) {
                if(mat[r][c] == 0) {
                    qu.push({r, c});
                    visited.insert({r, c});
                }
            }
        }
        for(int r = 0 ; r < row ; r++) {
            for(int c = 0 ; c < col ; c++) {
                mat[r][c] = 0;
            }
        }
        int level = 1;
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
                    if(new_r < 0 || new_c < 0 || new_r >= row || new_c >= col || visited.find({new_r, new_c}) != visited.end()) continue;
                    mat[new_r][new_c] = level;
                    qu.push({new_r, new_c});
                    visited.insert({new_r, new_c});
                }
            }
            level++;
        }
        return mat;
    }
};

int main(){
    
    return 0;
}