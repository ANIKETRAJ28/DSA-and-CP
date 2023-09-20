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

    memset(dp, -1, sizeof(dp));

    cout<<ftd(v, 0, 0);

    return 0;
}