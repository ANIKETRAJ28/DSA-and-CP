#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define vec vector<ll>
#define vecvec vector<vector<ll>>
using namespace std;

// https://cses.fi/problemset/task/1746/

vecvec dp;
int n, m;
vector<int> arr; 

ll ftd(int i, int x){
    if(i == 0||x == 0) return dp[i][x] = 0; 
    if(x > m) return dp[i][x] = 0; 

    if(i==1){
        if(arr[i] == x||arr[i] == 0)
        return dp[i][x] = 1;
        return dp[i][x] = 0;   
    }

    if(dp[i][x] != -1) return dp[i][x];
    ll cnt = 0;
    if(arr[i] == 0 || arr[i] == x){
        cnt = (ftd(i-1, x-1) % mod + ftd(i-1, x) % mod + ftd(i-1, x+1) % mod)% mod;
    }
    else return dp[i][x] = 0;
    return dp[i][x] = cnt;
}

int main(){
    cin>>n>>m;
    arr.clear();
    arr.resize(n+1);
    for(int i = 1 ; i <= n ; i++){
        cin>>arr[i];
    }
    dp.clear();
    dp.resize(n+2, vec(m+2, -1));

    ll ans = 0;
    for(int i = 1 ; i <= m ; i++){
        ftd(n, i);
    }
    for(int i = 1 ; i <= m ; i++){
        ans = (ans % mod + dp[n][i]) % mod;
    }
    cout<<ans;
    return 0;
}