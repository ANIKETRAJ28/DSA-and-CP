#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/rotting-oranges/

class Solution {
public:

    vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fo = 0;
        queue<pair<int, int>> qu;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1) fo++;
                else if(grid[i][j] == 2) qu.push({i, j});
            }
        }
        qu.push({-1, -1}); // for min
        int tim = 0;

        while(not qu.empty()){
            auto cell = qu.front();
            qu.pop();
            int r = cell.first;
            int c = cell.second;
            if(r == -1 && c == -1){
                tim++;
                if(not qu.empty()){
                    qu.push({-1, -1});
                }
                else break;
            }
            else{
                for(int d = 0 ; d < 4 ; d++){
                    int new_r = r + dir[d][0];
                    int new_c = c + dir[d][1];
                    if(new_r < 0 || new_r >= n || new_c < 0 || new_c >= m || grid[new_r][new_c] != 1) continue;
                    fo--;
                    grid[new_r][new_c] = 2;
                    qu.push({new_r, new_c});
                }
            }
        }
        return (fo == 0) ? tim-1 : -1;
    }
};

int main(){
    
    return 0;
}