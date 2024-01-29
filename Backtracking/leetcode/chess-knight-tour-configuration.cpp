#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/check-knight-tour-configuration/description/

class Solution {
public:
    int m = 0;
    vector<int> dx = {-1, -2, -2, -1, +1, +2, +2, +1};
    vector<int> dy = {-2, -1, +1, +2, +2, +1, -1, -2};

    bool check(vector<vector<int>>& grid, int i, int j, int num) {
        if(i < 0 or  i >= m or j < 0 or j >= m or grid[i][j] != num) return false;
        return true;
    }
    bool chess(vector<vector<int>>& grid, int i, int j, int num) {
        if(num == m*m-1) {
            return true;
        }

        for(int d = 0 ; d < 8 ; d++) {
            if(check(grid, i+dx[d], j+dy[d], num+1)) {
                if(chess(grid, i+dx[d], j+dy[d], num+1)) return true;
            }
        }

        return false;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        m = grid.size();
        if(grid[0][0] != 0) return false;
        return chess(grid, 0, 0, 0);
    }
};

int main(){
    
    return 0;
}