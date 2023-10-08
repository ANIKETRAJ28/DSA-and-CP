#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://www.codingninjas.com/studio/problems/walls-and-gates_1092887?leftPanelTab=1

vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

vector<vector<int>> wallsAndGates(vector<vector<int>> &a, int n, int m) {
    queue<pair<int, int>> qu;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) {
                qu.push({i, j});
            }
        }
    }
    
    while (!qu.empty()) {
        auto cell = qu.front();
        qu.pop();
        int r = cell.first;
        int c = cell.second;
        
        for (int d = 0; d < 4; d++) {
            int row = r + dir[d][0];
            int col = c + dir[d][1];
            
            if (row < 0 || row >= n || col < 0 || col >= m || a[row][col] == -1 || a[row][col] == 0) {
                continue;
            }
            
            if (a[row][col] > 1 + a[r][c]) {
                a[row][col] = 1 + a[r][c];
                qu.push({row, col});
            }
        }
    }
    
    return a;
}


int main(){
    
    return 0;
}