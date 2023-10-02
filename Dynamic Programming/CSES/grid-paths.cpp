#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

// https://cses.fi/problemset/task/1638

int dp[1005][1005];

// top-down
int ftd(vector<vector<char>> &v, int top, int down){
    int n = v.size();
    if(top >= n || down >= n || v[top][down] == '*') return 0;
    if(top == n-1 && down == n-1) return 1;
    if(dp[top][down] != -1) return dp[top][down];

    int ans = 0;

    ans = (ans % mod + ftd(v, top+1, down) % mod + ftd(v, top, down+1) % mod) % mod;
    return dp[top][down] = ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<char>> v(n, vector<char> (n));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>v[i][j];
        }
    }
    // memset(dp, -1, sizeof(dp));
    // cout<<ftd(v, 0, 0);
    memset(dp, 0, sizeof(dp));

    // bottom-up
    if(v[n-1][n-1] == '.') dp[n-1][n-1] = 1;
    
    for(int i = n-2 ; i >= 0 ; i--){
        if(v[n-1][i] == '.') dp[n-1][i] += dp[n-1][i+1];
    }

    for(int i = n-2 ; i >= 0 ; i--){
        if(v[i][n-1] == '.') dp[i][n-1] += dp[i+1][n-1];
    }

    for(int i = n-2 ; i >= 0 ; i--){
        for(int j = n-2 ; j >= 0 ; j--){
            if(v[i][j] != '*') dp[i][j] = (dp[i][j+1] % mod + dp[i+1][j] % mod) % mod;
        }
    }
    
    cout<<dp[0][0];

    return 0;
}