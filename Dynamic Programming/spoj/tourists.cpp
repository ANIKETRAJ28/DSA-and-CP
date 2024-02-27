#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://www.spoj.com/problems/TOURIST/

ll n, m;
char mat[105][105];
ll dp[105][105][105];

ll ftd(int i, int j, int x, int y) {
    // base case
    if(i > n or j > m or x > n or y > m or mat[i][j] == '#' or mat[x][y] == '#') return 0;
    if(i == n and j == m) {
        return mat[i][j] == '*';
    }
    if(dp[i][j][x] != -1) return dp[i][j][x];

    ll res = infn;

    res = max(res, ftd(i+1, j, x+1, y));     
    res = max(res, ftd(i+1, j, x, y+1));    
    res = max(res, ftd(i, j+1, x+1, y));    
    res = max(res, ftd(i, j+1, x, y+1));

    res += (mat[i][j] == '*');
    res += (mat[x][y] == '*');

    if(i == x and j == y and mat[i][j] == '*') res--;

    return dp[i][j][x] = res;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        cin>>m>>n;
        memset(dp, -1, sizeof dp);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cin>>mat[i][j];
            }
        }
        cout<<ftd(1,1,1,1)<<"\n";
    }
    return 0;
}