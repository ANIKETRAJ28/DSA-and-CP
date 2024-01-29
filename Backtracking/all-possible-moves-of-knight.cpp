#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

int n = 5;

vector<int> dx = {-1, -2, -2, -1, +1, +2, +2, +1};
vector<int> dy = {-2, -1, +1, +2, +2, +1, -1, -2};

bool check(vector<vector<int>>& grid, int i, int j) {
    return i >= 0 and  i < n and j >= 0 and j < n and grid[i][j] == -1;
}

void knight(vec<vec<int>> &grid, int i, int j, int val) {
    if(val == n*n-1) {
        grid[i][j] = n*n-1;
        cout<<"\n*********************\n";
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                cout<<grid[i][j]<<"   ";
            }
            cout<<"\n";
        }
        grid[i][j] = -1;
        return;
    }
    for(int d = 0 ; d < 8 ; d++) {
        if(check(grid, i+dx[d], j+dy[d])) {
            grid[i][j] = val;
            knight(grid, i+dx[d], j+dy[d], val+1);
            grid[i][j] = -1;
        }
    }
}

int main(){
    vec<vec<int>> grid(n, vec<int> (n, -1));
    knight(grid, 0, 0, 0);
    return 0;
}